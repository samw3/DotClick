
@vs vs
in vec4 position;
in vec2 texcoord0;

layout(location=1) out vec2 uv;

void main() {
    gl_Position = position;
    uv = texcoord0;
}
@end

@fs fs
uniform sampler2D tex;
layout(location=1) in vec2 uv;
out vec4 frag_color;

void main() {
    frag_color = texture(tex, uv);
}
@end

@fs crt_fs
const float PI = 3.14159265359;
const bool  show_curvature = true;
const bool  show_vignette = true;
const bool  show_horizontal_scan_lines = true;
const vec2  screen_size = vec2(1920.0, 1080.0);
const vec4  corner_color = vec4(0.0, 0.0, 0.0, 1.0);
const float curvature_x_amount = float(10.0); // hint_range(3.0, 15.0, 0.01)
const float curvature_y_amount = float(5.5); // hint_range(3.0, 15.0, 0.01)
const float vignette_opacity = 0.1; // hint_range(0.0, 1.0, 0.01)
const float horizontal_scan_lines_amount = 72.0; // hint_range(0.0, 72.0, 0.1)
const float horizontal_scan_lines_opacity = 0.1; // hint_range(0.0, 1.0, 0.01)
const float boost = 1.2; // hint_range(1.0, 2.0, 0.01)
const float aberration_amount = 3.0; // hint_range(0.0, 10.0, 0.01) 

uniform sampler2D tex;
layout(location=1) in vec2 uv;
out vec4 frag_color;

vec2 uv_curve(vec2 uv) {
    if (show_curvature) {
        uv = uv * 2.0 - 1.0;
        vec2 offset = abs(uv.yx) / vec2(curvature_x_amount, curvature_y_amount);
        uv = uv + uv * offset * offset;
        uv = uv * 0.5 + 0.5;
    }

    return uv;
}

void main() {
    //frag_color = texture(tex, uv); return;
    vec2 uv = uv_curve(uv);
    vec3 color = texture(tex, uv).rgb;

    if (aberration_amount > 0.0) {
        float adjusted_amount = aberration_amount / screen_size.x;
        float adjusted_amount_y = aberration_amount / screen_size.y;
        // color.r = texture(tex, vec2(uv.x + adjusted_amount, uv.y)).r;
        // color.g = texture(tex, uv).g;
        // color.b = texture(tex, vec2(uv.x - adjusted_amount, uv.y)).b;

        color = texture(tex, vec2(uv.x + adjusted_amount, uv.y+adjusted_amount_y)).rgb * 0.25;
        color += texture(tex, uv).rgb * 0.5;
        color += texture(tex, vec2(uv.x - adjusted_amount, uv.y+adjusted_amount_y)).rgb * 0.25;

    }

    if (show_vignette) {
        float vignette = uv.x * uv.y * (1.0 - uv.x) * (1.0 - uv.y);
        vignette = clamp(pow((screen_size.x / 4.0) * vignette, vignette_opacity), 0.0, 1.0);
        color *= vignette;
    }

    if (show_horizontal_scan_lines) {
        float s = sin(uv.y * horizontal_scan_lines_amount * PI * 2.0 - 0.5);
        s = (s * 0.5 + 0.5) * 0.5 + 0.5;
        vec4 scan_line = vec4(vec3(pow(s, horizontal_scan_lines_opacity)), 1.0);
        color *= s;// scan_line.rgb;
        color *= boost;
    }

    // Fill the blank space of the corners, left by the curvature, with black.
    if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0) {
        color = corner_color.rgb;
    }

    frag_color = vec4(color, 1.0);
}

@end

@program dot_click vs fs

@program crt vs crt_fs