#define SOKOL_IMPL
#define SOKOL_METAL

#include "sokol_app.h"
#include "sokol_audio.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"
#define HANDMADE_MATH_IMPLEMENTATION
#define HANDMADE_MATH_NO_SSE
#include "HandmadeMath.h"
#include "dot_click.glsl.h"
//#include "crt.glsl.h"

#define DEFAULT_SCALE (12)
#define IMAGE_WIDTH (128)
#define IMAGE_HEIGHT (72)

//#define MIN(a,b) (((a)<(b))?(a):(b))
//#define MAX(a,b) (((a)>(b))?(a):(b))

static struct {
    struct {
        sg_pass_action pass_action;
        sg_pass pass;
        sg_pipeline pip;
        sg_bindings bind;
    } offscreen;
    struct {
        sg_pass_action pass_action;
        sg_pipeline pip;
        sg_bindings bind;
    } deflt;
    uint32_t pixels1[IMAGE_WIDTH * IMAGE_HEIGHT];
    uint32_t pixels2[IMAGE_WIDTH * IMAGE_HEIGHT];
    uint32_t *front;
    uint32_t *back;
    float audioBuffer[735];
    uint8_t input;
    int mousePosition;
} state;

extern uint8_t dot_click(uint16_t pos, uint8_t input);

void flip()
{
    uint32_t *tmp = state.front;
    state.front = state.back;
    state.back = tmp;
}

static uint32_t palette[] = {
    0xff080808, // 0
    0xff001c08, // 1
    0xff00005a, // 2
    0xff502300, // 3
    0xff585858, // 4
    0xffa120a9, // 5
    0xffbe4556, // 6
    0xff0d8e07, // 7
    0xff5e8df9, // 8
    0xff41a9b8, // 9
    0xffa9a9a9, // 10
    0xfff0c655, // 11
    0xfffec1fe, // 12
    0xffadfea7, // 13
    0xffe3e9fc, // 14
    0xfff9f9f9, // 15
};

void init(void) {
    saudio_setup(&(saudio_desc){0});
    assert(saudio_channels() == 1);

    sg_setup(&(sg_desc){
        .context = sapp_sgcontext()
    });

    //  a 128x72 image with streaming update strategy 
    sg_image img = sg_make_image(&(sg_image_desc){
        .width = IMAGE_WIDTH,
        .height = IMAGE_HEIGHT,
        .pixel_format = SG_PIXELFORMAT_RGBA8,
        .usage = SG_USAGE_STREAM,
        .min_filter = SG_FILTER_NEAREST,
        .mag_filter = SG_FILTER_NEAREST,
        .wrap_u = SG_WRAP_CLAMP_TO_EDGE,
        .wrap_v = SG_WRAP_CLAMP_TO_EDGE,
        .label = "dynamic-texture"
    });

    //  vertex buffer 
    float vertices[] = {
        //  pos                 uvs 
        -1.0f, -1.0f,  1.0f,   0.0f, 1.0f,
         1.0f, -1.0f,  1.0f,   1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,   1.0f, 0.0f,
        -1.0f,  1.0f,  1.0f,   0.0f, 0.0f
    };
    uint16_t indices[] = {
        2, 1, 0,  3, 2, 0
    };

    sg_buffer vbuf = sg_make_buffer(&(sg_buffer_desc){
        .size = sizeof(vertices),
        .content = vertices,
        .label = "dotclick-vertices"
    });
    sg_buffer ibuf = sg_make_buffer(&(sg_buffer_desc){
        .type = SG_BUFFERTYPE_INDEXBUFFER,
        .size = sizeof(indices),
        .content = indices,
        .label = "dotclick-indices"
    });

    state.offscreen.pip = sg_make_pipeline(&(sg_pipeline_desc) {
        .layout = {
            .attrs = {
                [ATTR_vs_position].format  = SG_VERTEXFORMAT_FLOAT3,
                [ATTR_vs_texcoord0].format = SG_VERTEXFORMAT_FLOAT2
            }
        },
        .shader = sg_make_shader(dot_click_shader_desc()),
        .index_type = SG_INDEXTYPE_UINT16,
        .blend = {
            .color_format = SG_PIXELFORMAT_RGBA8,
            .depth_format = SG_PIXELFORMAT_DEPTH
        },
        .label = "dotclick-pipeline"
    });

    state.offscreen.bind = (sg_bindings) {
        .vertex_buffers[0] = vbuf,
        .index_buffer = ibuf,
        .fs_images[SLOT_tex] = img
    };

    sg_image_desc img_desc = {
        .render_target = true,
        .width = 1920,
        .height = 1080,
        .pixel_format = SG_PIXELFORMAT_RGBA8,
        .min_filter = SG_FILTER_LINEAR,
        .mag_filter = SG_FILTER_LINEAR,
        .wrap_u = SG_WRAP_CLAMP_TO_EDGE,
        .wrap_v = SG_WRAP_CLAMP_TO_EDGE,
        .sample_count = 4,
        .label = "dot_click-image"
    };
    sg_image dot_click_image = sg_make_image(&img_desc);

    img_desc.pixel_format = SG_PIXELFORMAT_DEPTH;
    img_desc.label = "depth-image";
    sg_image depth_img = sg_make_image(&img_desc);

    state.offscreen.pass = sg_make_pass(&(sg_pass_desc){
        .color_attachments[0].image = dot_click_image,
        .depth_stencil_attachment.image = depth_img,
        .label = "dot_click-pass"
    });

    state.deflt.pip = sg_make_pipeline(&(sg_pipeline_desc){
        .layout = {
            .attrs = {
                [ATTR_vs_position].format  = SG_VERTEXFORMAT_FLOAT3,
                [ATTR_vs_texcoord0].format = SG_VERTEXFORMAT_FLOAT2
            }
        },
        .shader = sg_make_shader(crt_shader_desc()),
        .index_type = SG_INDEXTYPE_UINT16,
        .label = "default-pipeline"
    });

    state.deflt.bind = (sg_bindings) {
        .vertex_buffers[0] = vbuf,
        .index_buffer = ibuf,
        .fs_images[SLOT_tex] = dot_click_image
    };

    state.front = state.pixels1;
    state.back = state.pixels2;
    state.input = 0;
    state.mousePosition = -1;
}

void frame(void) {
    static int dot = 0;
    for (int i = 0; i < 735; i++) {
        int sample = 0;
        for (int i = 0; i < 16; ++i) {
            const uint8_t output = dot_click(dot, state.input | ((state.mousePosition == dot) ? 0x80 : 0x00));
            if (dot < 9216) state.pixels1[dot] = palette[(output >> 4) & 0xf];
            sample += output & 0xf;
            dot++;
            if (dot == 11760) dot = 0;
        }
        state.audioBuffer[i] = sample / 120.0f - 1.0f;
    }
    saudio_push(state.audioBuffer, 735);

    //  update the texture 
    sg_update_image(state.offscreen.bind.fs_images[0], &(sg_image_content){
        .subimage[0][0] = {
            .ptr = state.front,
            .size = sizeof(state.pixels1)
        }
    });

    //  render the frame 
    sg_begin_pass(state.offscreen.pass, &state.offscreen.pass_action);
    sg_apply_pipeline(state.offscreen.pip);
    sg_apply_bindings(&state.offscreen.bind);
    sg_draw(0, 6, 1);
    sg_end_pass();

    sg_begin_default_pass(&state.deflt.pass_action, sapp_width(), sapp_height());
    sg_apply_pipeline(state.deflt.pip);
    sg_apply_bindings(&state.deflt.bind);
    sg_draw(0, 6, 1);
    sg_end_pass();

    sg_commit();
}

void cleanup(void) {
    sg_shutdown();
    saudio_shutdown();
}

int getMousePosition(float mouseX, float mouseY)
{
    int x = (int) mouseX / (sapp_width() / IMAGE_WIDTH);
    int y = (int) mouseY / (sapp_height() / IMAGE_HEIGHT);
    if (x >= 0 && x < IMAGE_WIDTH &&
        y >= 0 && y < IMAGE_HEIGHT)
    {
        sapp_show_mouse(false);
        return(MAX(0, MIN(71, y)) * 128 + MAX(0, MIN(127, x)));
    }
    else
    {
        sapp_show_mouse(true);
        return -1;
    }
}

static void event(const sapp_event* e) {
    assert((e->type >= 0) && (e->type < _SAPP_EVENTTYPE_NUM));

    if ((e->type == SAPP_EVENTTYPE_KEY_DOWN) && !e->key_repeat) {
        switch (e->key_code) {
            case SAPP_KEYCODE_UP:
            case SAPP_KEYCODE_W:
                state.input |= 0x1;
                break;
            case SAPP_KEYCODE_DOWN:
            case SAPP_KEYCODE_S:
                state.input |= 0x2;
                break;
            case SAPP_KEYCODE_LEFT:
            case SAPP_KEYCODE_A:
                state.input |= 0x4;
                break;
            case SAPP_KEYCODE_RIGHT:
            case SAPP_KEYCODE_D:
                state.input |= 0x8;
                break;
            case SAPP_KEYCODE_SPACE:
            case SAPP_KEYCODE_ENTER:
            case SAPP_KEYCODE_Z:
                state.input |= 0x10;
                break;
            case SAPP_KEYCODE_ESCAPE:
            case SAPP_KEYCODE_X:
                state.input |= 0x20;
                break;
            default:
                break;
        }
    }
    else if (e->type == SAPP_EVENTTYPE_KEY_UP) {
        switch (e->key_code) {
            case SAPP_KEYCODE_UP:
            case SAPP_KEYCODE_W:
                state.input &= ~0x1;
                break;
            case SAPP_KEYCODE_DOWN:
            case SAPP_KEYCODE_S:
                state.input &= ~0x2;
                break;
            case SAPP_KEYCODE_LEFT:
            case SAPP_KEYCODE_A:
                state.input &= ~0x4;
                break;
            case SAPP_KEYCODE_RIGHT:
            case SAPP_KEYCODE_D:
                state.input &= ~0x8;
                break;
            case SAPP_KEYCODE_SPACE:
            case SAPP_KEYCODE_ENTER:
            case SAPP_KEYCODE_Z:
                state.input &= ~0x10;
                break;
            case SAPP_KEYCODE_ESCAPE:
            case SAPP_KEYCODE_X:
                state.input &= ~0x20;
                break;
            default:
                break;
        }
    }
    else if (e->type == SAPP_EVENTTYPE_MOUSE_DOWN)
    {
        state.input |= 0x40;
        state.mousePosition = getMousePosition(e->mouse_x, e->mouse_y);
    }
    else if (e->type == SAPP_EVENTTYPE_MOUSE_UP)
    {
        state.input &= ~0x40;
        state.mousePosition = getMousePosition(e->mouse_x, e->mouse_y);
    }
    else if (e->type == SAPP_EVENTTYPE_MOUSE_MOVE)
    {
        state.mousePosition = getMousePosition(e->mouse_x, e->mouse_y);
    }
    else if (e->type == SAPP_EVENTTYPE_MOUSE_ENTER)
    {
        state.mousePosition = getMousePosition(e->mouse_x, e->mouse_y);
    }
    else if (e->type == SAPP_EVENTTYPE_MOUSE_LEAVE)
    {
        state.mousePosition = getMousePosition(e->mouse_x, e->mouse_y);
    }
}

sapp_desc sokol_main(int argc, char* argv[]) {
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = event,
        .width = IMAGE_WIDTH * DEFAULT_SCALE,
        .height = IMAGE_HEIGHT * DEFAULT_SCALE,
        .high_dpi = true,
        .sample_count = 4,
        //.gl_force_gles2 = true,
        .window_title = "DOT CLICK",
    };
}

