#pragma once
/*
    #version:1# (machine generated, don't edit!)

    Generated by sokol-shdc (https://github.com/floooh/sokol-tools)

    Overview:

        Shader program 'crt':
            Get shader desc: crt_shader_desc()
            Vertex shader: vs
                Attribute slots:
                    ATTR_vs_position = 0
                    ATTR_vs_texcoord0 = 1
            Fragment shader: crt_fs
                Image 'tex':
                    Type: SG_IMAGETYPE_2D
                    Component Type: SG_SAMPLERTYPE_FLOAT
                    Bind slot: SLOT_tex = 0

        Shader program 'dot_click':
            Get shader desc: dot_click_shader_desc()
            Vertex shader: vs
                Attribute slots:
                    ATTR_vs_position = 0
                    ATTR_vs_texcoord0 = 1
            Fragment shader: fs
                Image 'tex':
                    Type: SG_IMAGETYPE_2D
                    Component Type: SG_SAMPLERTYPE_FLOAT
                    Bind slot: SLOT_tex = 0


    Shader descriptor structs:

        sg_shader crt = sg_make_shader(crt_shader_desc());
        sg_shader dot_click = sg_make_shader(dot_click_shader_desc());

    Vertex attribute locations for vertex shader 'vs':

        sg_pipeline pip = sg_make_pipeline(&(sg_pipeline_desc){
            .layout = {
                .attrs = {
                    [ATTR_vs_position] = { ... },
                    [ATTR_vs_texcoord0] = { ... },
                },
            },
            ...});

    Image bind slots, use as index in sg_bindings.vs_images[] or .fs_images[]

        SLOT_tex = 0;

*/
#include <stdint.h>
#include <stdbool.h>
#if !defined(SOKOL_SHDC_ALIGN)
  #if defined(_MSC_VER)
    #define SOKOL_SHDC_ALIGN(a) __declspec(align(a))
  #else
    #define SOKOL_SHDC_ALIGN(a) __attribute__((aligned(a)))
  #endif
#endif
#define ATTR_vs_position (0)
#define ATTR_vs_texcoord0 (1)
#define SLOT_tex (0)
/*
    #include <metal_stdlib>
    #include <simd/simd.h>
    
    using namespace metal;
    
    struct main0_out
    {
        float2 uv [[user(locn1)]];
        float4 gl_Position [[position]];
    };
    
    struct main0_in
    {
        float4 position [[attribute(0)]];
        float2 texcoord0 [[attribute(1)]];
    };
    
    #line 12 ""
    vertex main0_out main0(main0_in in [[stage_in]])
    {
        main0_out out = {};
    #line 12 ""
        out.gl_Position = in.position;
    #line 13 ""
        out.uv = in.texcoord0;
        return out;
    }
    
*/
static const char vs_source_metal_macos[455] = {
    0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x3c,0x6d,0x65,0x74,0x61,0x6c,0x5f,
    0x73,0x74,0x64,0x6c,0x69,0x62,0x3e,0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,
    0x20,0x3c,0x73,0x69,0x6d,0x64,0x2f,0x73,0x69,0x6d,0x64,0x2e,0x68,0x3e,0x0a,0x0a,
    0x75,0x73,0x69,0x6e,0x67,0x20,0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,0x20,
    0x6d,0x65,0x74,0x61,0x6c,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x32,0x20,0x75,0x76,0x20,0x5b,0x5b,0x75,0x73,0x65,0x72,0x28,
    0x6c,0x6f,0x63,0x6e,0x31,0x29,0x5d,0x5d,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,
    0x6f,0x61,0x74,0x34,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,
    0x20,0x5b,0x5b,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x5d,0x5d,0x3b,0x0a,0x7d,
    0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,
    0x69,0x6e,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,
    0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x5b,0x5b,0x61,0x74,0x74,0x72,0x69,
    0x62,0x75,0x74,0x65,0x28,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x32,0x20,0x74,0x65,0x78,0x63,0x6f,0x6f,0x72,0x64,0x30,0x20,
    0x5b,0x5b,0x61,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x28,0x31,0x29,0x5d,0x5d,
    0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x31,0x32,0x20,0x22,
    0x22,0x0a,0x76,0x65,0x72,0x74,0x65,0x78,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,
    0x75,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x28,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x69,
    0x6e,0x20,0x69,0x6e,0x20,0x5b,0x5b,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,0x5d,
    0x5d,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,
    0x75,0x74,0x20,0x6f,0x75,0x74,0x20,0x3d,0x20,0x7b,0x7d,0x3b,0x0a,0x23,0x6c,0x69,
    0x6e,0x65,0x20,0x31,0x32,0x20,0x22,0x22,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x74,
    0x2e,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x69,
    0x6e,0x2e,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x23,0x6c,0x69,0x6e,
    0x65,0x20,0x31,0x33,0x20,0x22,0x22,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x74,0x2e,
    0x75,0x76,0x20,0x3d,0x20,0x69,0x6e,0x2e,0x74,0x65,0x78,0x63,0x6f,0x6f,0x72,0x64,
    0x30,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x6f,0x75,
    0x74,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #include <metal_stdlib>
    #include <simd/simd.h>
    
    using namespace metal;
    
    struct main0_out
    {
        float4 frag_color [[color(0)]];
    };
    
    struct main0_in
    {
        float2 uv [[user(locn1)]];
    };
    
    #line 11 ""
    fragment main0_out main0(main0_in in [[stage_in]], texture2d<float> tex [[texture(0)]], sampler texSmplr [[sampler(0)]])
    {
        main0_out out = {};
    #line 11 ""
        out.frag_color = tex.sample(texSmplr, in.uv);
        return out;
    }
    
*/
static const char fs_source_metal_macos[425] = {
    0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x3c,0x6d,0x65,0x74,0x61,0x6c,0x5f,
    0x73,0x74,0x64,0x6c,0x69,0x62,0x3e,0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,
    0x20,0x3c,0x73,0x69,0x6d,0x64,0x2f,0x73,0x69,0x6d,0x64,0x2e,0x68,0x3e,0x0a,0x0a,
    0x75,0x73,0x69,0x6e,0x67,0x20,0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,0x20,
    0x6d,0x65,0x74,0x61,0x6c,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x34,0x20,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,
    0x20,0x5b,0x5b,0x63,0x6f,0x6c,0x6f,0x72,0x28,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,
    0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,
    0x69,0x6e,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,
    0x75,0x76,0x20,0x5b,0x5b,0x75,0x73,0x65,0x72,0x28,0x6c,0x6f,0x63,0x6e,0x31,0x29,
    0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x31,0x31,
    0x20,0x22,0x22,0x0a,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x20,0x6d,0x61,0x69,
    0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x28,0x6d,0x61,0x69,
    0x6e,0x30,0x5f,0x69,0x6e,0x20,0x69,0x6e,0x20,0x5b,0x5b,0x73,0x74,0x61,0x67,0x65,
    0x5f,0x69,0x6e,0x5d,0x5d,0x2c,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x32,0x64,
    0x3c,0x66,0x6c,0x6f,0x61,0x74,0x3e,0x20,0x74,0x65,0x78,0x20,0x5b,0x5b,0x74,0x65,
    0x78,0x74,0x75,0x72,0x65,0x28,0x30,0x29,0x5d,0x5d,0x2c,0x20,0x73,0x61,0x6d,0x70,
    0x6c,0x65,0x72,0x20,0x74,0x65,0x78,0x53,0x6d,0x70,0x6c,0x72,0x20,0x5b,0x5b,0x73,
    0x61,0x6d,0x70,0x6c,0x65,0x72,0x28,0x30,0x29,0x5d,0x5d,0x29,0x0a,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6f,0x75,0x74,
    0x20,0x3d,0x20,0x7b,0x7d,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x31,0x31,0x20,
    0x22,0x22,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x74,0x2e,0x66,0x72,0x61,0x67,0x5f,
    0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x74,0x65,0x78,0x2e,0x73,0x61,0x6d,0x70,
    0x6c,0x65,0x28,0x74,0x65,0x78,0x53,0x6d,0x70,0x6c,0x72,0x2c,0x20,0x69,0x6e,0x2e,
    0x75,0x76,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,
    0x6f,0x75,0x74,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #pragma clang diagnostic ignored "-Wmissing-prototypes"
    
    #include <metal_stdlib>
    #include <simd/simd.h>
    
    using namespace metal;
    
    struct main0_out
    {
        float4 frag_color [[color(0)]];
    };
    
    struct main0_in
    {
        float2 uv [[user(locn1)]];
    };
    
    #line 26 ""
    static inline __attribute__((always_inline))
    float2 uv_curve(thread float2& uv)
    {
    #line 26 ""
        uv = (uv * 2.0) - float2(1.0);
    #line 27 ""
        float2 _31 = abs(uv.yx) * float2(0.100000001490116119384765625, 0.181818187236785888671875);
    #line 28 ""
        uv += ((uv * _31) * _31);
    #line 29 ""
        uv = (uv * 0.5) + float2(0.5);
    #line 32 ""
        return uv;
    }
    
    #line 37 ""
    fragment main0_out main0(main0_in in [[stage_in]], texture2d<float> tex [[texture(0)]], sampler texSmplr [[sampler(0)]])
    {
        main0_out out = {};
    #line 37 ""
        float2 param = in.uv;
        float2 _52 = uv_curve(param);
    #line 38 ""
        float3 color = tex.sample(texSmplr, _52).xyz;
        float _83 = _52.y + 0.00277777784503996372222900390625;
        color = ((tex.sample(texSmplr, float2(_52.x + 0.001562500023283064365386962890625, _83)).xyz * 0.25) + (tex.sample(texSmplr, _52).xyz * 0.5)) + (tex.sample(texSmplr, float2(_52.x - 0.001562500023283064365386962890625, _83)).xyz * 0.25);
        color *= fast::clamp(pow(480.0 * (((_52.x * _52.y) * (1.0 - _52.x)) * (1.0 - _52.y)), 0.100000001490116119384765625), 0.0, 1.0);
        color = (color * ((((sin((_52.y * 452.38934326171875) - 0.5) * 0.5) + 0.5) * 0.5) + 0.5)) * 1.2000000476837158203125;
        bool _171 = _52.x < 0.0;
        bool _178;
        if (!_171)
        {
            _178 = _52.x > 1.0;
        }
        else
        {
            _178 = _171;
        }
        bool _185;
        if (!_178)
        {
            _185 = _52.y < 0.0;
        }
        else
        {
            _185 = _178;
        }
        bool _192;
        if (!_185)
        {
            _192 = _52.y > 1.0;
        }
        else
        {
            _192 = _185;
        }
        if (_192)
        {
    #line 69 ""
            color = float3(0.0);
        }
    #line 72 ""
        out.frag_color = float4(color, 1.0);
        return out;
    }
    
*/
static const char crt_fs_source_metal_macos[1964] = {
    0x23,0x70,0x72,0x61,0x67,0x6d,0x61,0x20,0x63,0x6c,0x61,0x6e,0x67,0x20,0x64,0x69,
    0x61,0x67,0x6e,0x6f,0x73,0x74,0x69,0x63,0x20,0x69,0x67,0x6e,0x6f,0x72,0x65,0x64,
    0x20,0x22,0x2d,0x57,0x6d,0x69,0x73,0x73,0x69,0x6e,0x67,0x2d,0x70,0x72,0x6f,0x74,
    0x6f,0x74,0x79,0x70,0x65,0x73,0x22,0x0a,0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,
    0x65,0x20,0x3c,0x6d,0x65,0x74,0x61,0x6c,0x5f,0x73,0x74,0x64,0x6c,0x69,0x62,0x3e,
    0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x3c,0x73,0x69,0x6d,0x64,0x2f,
    0x73,0x69,0x6d,0x64,0x2e,0x68,0x3e,0x0a,0x0a,0x75,0x73,0x69,0x6e,0x67,0x20,0x6e,
    0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,0x20,0x6d,0x65,0x74,0x61,0x6c,0x3b,0x0a,
    0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,
    0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x5b,0x5b,0x63,0x6f,0x6c,0x6f,
    0x72,0x28,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,
    0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x0a,0x7b,0x0a,0x20,0x20,
    0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x75,0x76,0x20,0x5b,0x5b,0x75,0x73,
    0x65,0x72,0x28,0x6c,0x6f,0x63,0x6e,0x31,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,
    0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x32,0x36,0x20,0x22,0x22,0x0a,0x73,0x74,0x61,
    0x74,0x69,0x63,0x20,0x69,0x6e,0x6c,0x69,0x6e,0x65,0x20,0x5f,0x5f,0x61,0x74,0x74,
    0x72,0x69,0x62,0x75,0x74,0x65,0x5f,0x5f,0x28,0x28,0x61,0x6c,0x77,0x61,0x79,0x73,
    0x5f,0x69,0x6e,0x6c,0x69,0x6e,0x65,0x29,0x29,0x0a,0x66,0x6c,0x6f,0x61,0x74,0x32,
    0x20,0x75,0x76,0x5f,0x63,0x75,0x72,0x76,0x65,0x28,0x74,0x68,0x72,0x65,0x61,0x64,
    0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x26,0x20,0x75,0x76,0x29,0x0a,0x7b,0x0a,0x23,
    0x6c,0x69,0x6e,0x65,0x20,0x32,0x36,0x20,0x22,0x22,0x0a,0x20,0x20,0x20,0x20,0x75,
    0x76,0x20,0x3d,0x20,0x28,0x75,0x76,0x20,0x2a,0x20,0x32,0x2e,0x30,0x29,0x20,0x2d,
    0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x28,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x23,0x6c,
    0x69,0x6e,0x65,0x20,0x32,0x37,0x20,0x22,0x22,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,
    0x6f,0x61,0x74,0x32,0x20,0x5f,0x33,0x31,0x20,0x3d,0x20,0x61,0x62,0x73,0x28,0x75,
    0x76,0x2e,0x79,0x78,0x29,0x20,0x2a,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x28,0x30,
    0x2e,0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x34,0x39,0x30,0x31,0x31,0x36,
    0x31,0x31,0x39,0x33,0x38,0x34,0x37,0x36,0x35,0x36,0x32,0x35,0x2c,0x20,0x30,0x2e,
    0x31,0x38,0x31,0x38,0x31,0x38,0x31,0x38,0x37,0x32,0x33,0x36,0x37,0x38,0x35,0x38,
    0x38,0x38,0x36,0x37,0x31,0x38,0x37,0x35,0x29,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,
    0x20,0x32,0x38,0x20,0x22,0x22,0x0a,0x20,0x20,0x20,0x20,0x75,0x76,0x20,0x2b,0x3d,
    0x20,0x28,0x28,0x75,0x76,0x20,0x2a,0x20,0x5f,0x33,0x31,0x29,0x20,0x2a,0x20,0x5f,
    0x33,0x31,0x29,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x32,0x39,0x20,0x22,0x22,
    0x0a,0x20,0x20,0x20,0x20,0x75,0x76,0x20,0x3d,0x20,0x28,0x75,0x76,0x20,0x2a,0x20,
    0x30,0x2e,0x35,0x29,0x20,0x2b,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x28,0x30,0x2e,
    0x35,0x29,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x33,0x32,0x20,0x22,0x22,0x0a,
    0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x75,0x76,0x3b,0x0a,0x7d,
    0x0a,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x33,0x37,0x20,0x22,0x22,0x0a,0x66,0x72,
    0x61,0x67,0x6d,0x65,0x6e,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,
    0x20,0x6d,0x61,0x69,0x6e,0x30,0x28,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x20,
    0x69,0x6e,0x20,0x5b,0x5b,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,0x5d,0x5d,0x2c,
    0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x32,0x64,0x3c,0x66,0x6c,0x6f,0x61,0x74,
    0x3e,0x20,0x74,0x65,0x78,0x20,0x5b,0x5b,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,
    0x30,0x29,0x5d,0x5d,0x2c,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,0x20,0x74,0x65,
    0x78,0x53,0x6d,0x70,0x6c,0x72,0x20,0x5b,0x5b,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,
    0x28,0x30,0x29,0x5d,0x5d,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x69,
    0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6f,0x75,0x74,0x20,0x3d,0x20,0x7b,0x7d,0x3b,
    0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x33,0x37,0x20,0x22,0x22,0x0a,0x20,0x20,0x20,
    0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x70,0x61,0x72,0x61,0x6d,0x20,0x3d,0x20,
    0x69,0x6e,0x2e,0x75,0x76,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x32,0x20,0x5f,0x35,0x32,0x20,0x3d,0x20,0x75,0x76,0x5f,0x63,0x75,0x72,0x76,0x65,
    0x28,0x70,0x61,0x72,0x61,0x6d,0x29,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x33,
    0x38,0x20,0x22,0x22,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x33,0x20,
    0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x74,0x65,0x78,0x2e,0x73,0x61,0x6d,0x70,
    0x6c,0x65,0x28,0x74,0x65,0x78,0x53,0x6d,0x70,0x6c,0x72,0x2c,0x20,0x5f,0x35,0x32,
    0x29,0x2e,0x78,0x79,0x7a,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x20,0x5f,0x38,0x33,0x20,0x3d,0x20,0x5f,0x35,0x32,0x2e,0x79,0x20,0x2b,0x20,0x30,
    0x2e,0x30,0x30,0x32,0x37,0x37,0x37,0x37,0x37,0x37,0x38,0x34,0x35,0x30,0x33,0x39,
    0x39,0x36,0x33,0x37,0x32,0x32,0x32,0x32,0x39,0x30,0x30,0x33,0x39,0x30,0x36,0x32,
    0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x28,
    0x28,0x74,0x65,0x78,0x2e,0x73,0x61,0x6d,0x70,0x6c,0x65,0x28,0x74,0x65,0x78,0x53,
    0x6d,0x70,0x6c,0x72,0x2c,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x28,0x5f,0x35,0x32,
    0x2e,0x78,0x20,0x2b,0x20,0x30,0x2e,0x30,0x30,0x31,0x35,0x36,0x32,0x35,0x30,0x30,
    0x30,0x32,0x33,0x32,0x38,0x33,0x30,0x36,0x34,0x33,0x36,0x35,0x33,0x38,0x36,0x39,
    0x36,0x32,0x38,0x39,0x30,0x36,0x32,0x35,0x2c,0x20,0x5f,0x38,0x33,0x29,0x29,0x2e,
    0x78,0x79,0x7a,0x20,0x2a,0x20,0x30,0x2e,0x32,0x35,0x29,0x20,0x2b,0x20,0x28,0x74,
    0x65,0x78,0x2e,0x73,0x61,0x6d,0x70,0x6c,0x65,0x28,0x74,0x65,0x78,0x53,0x6d,0x70,
    0x6c,0x72,0x2c,0x20,0x5f,0x35,0x32,0x29,0x2e,0x78,0x79,0x7a,0x20,0x2a,0x20,0x30,
    0x2e,0x35,0x29,0x29,0x20,0x2b,0x20,0x28,0x74,0x65,0x78,0x2e,0x73,0x61,0x6d,0x70,
    0x6c,0x65,0x28,0x74,0x65,0x78,0x53,0x6d,0x70,0x6c,0x72,0x2c,0x20,0x66,0x6c,0x6f,
    0x61,0x74,0x32,0x28,0x5f,0x35,0x32,0x2e,0x78,0x20,0x2d,0x20,0x30,0x2e,0x30,0x30,
    0x31,0x35,0x36,0x32,0x35,0x30,0x30,0x30,0x32,0x33,0x32,0x38,0x33,0x30,0x36,0x34,
    0x33,0x36,0x35,0x33,0x38,0x36,0x39,0x36,0x32,0x38,0x39,0x30,0x36,0x32,0x35,0x2c,
    0x20,0x5f,0x38,0x33,0x29,0x29,0x2e,0x78,0x79,0x7a,0x20,0x2a,0x20,0x30,0x2e,0x32,
    0x35,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x2a,0x3d,
    0x20,0x66,0x61,0x73,0x74,0x3a,0x3a,0x63,0x6c,0x61,0x6d,0x70,0x28,0x70,0x6f,0x77,
    0x28,0x34,0x38,0x30,0x2e,0x30,0x20,0x2a,0x20,0x28,0x28,0x28,0x5f,0x35,0x32,0x2e,
    0x78,0x20,0x2a,0x20,0x5f,0x35,0x32,0x2e,0x79,0x29,0x20,0x2a,0x20,0x28,0x31,0x2e,
    0x30,0x20,0x2d,0x20,0x5f,0x35,0x32,0x2e,0x78,0x29,0x29,0x20,0x2a,0x20,0x28,0x31,
    0x2e,0x30,0x20,0x2d,0x20,0x5f,0x35,0x32,0x2e,0x79,0x29,0x29,0x2c,0x20,0x30,0x2e,
    0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x34,0x39,0x30,0x31,0x31,0x36,0x31,
    0x31,0x39,0x33,0x38,0x34,0x37,0x36,0x35,0x36,0x32,0x35,0x29,0x2c,0x20,0x30,0x2e,
    0x30,0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x63,0x6f,0x6c,
    0x6f,0x72,0x20,0x3d,0x20,0x28,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x2a,0x20,0x28,0x28,
    0x28,0x28,0x73,0x69,0x6e,0x28,0x28,0x5f,0x35,0x32,0x2e,0x79,0x20,0x2a,0x20,0x34,
    0x35,0x32,0x2e,0x33,0x38,0x39,0x33,0x34,0x33,0x32,0x36,0x31,0x37,0x31,0x38,0x37,
    0x35,0x29,0x20,0x2d,0x20,0x30,0x2e,0x35,0x29,0x20,0x2a,0x20,0x30,0x2e,0x35,0x29,
    0x20,0x2b,0x20,0x30,0x2e,0x35,0x29,0x20,0x2a,0x20,0x30,0x2e,0x35,0x29,0x20,0x2b,
    0x20,0x30,0x2e,0x35,0x29,0x29,0x20,0x2a,0x20,0x31,0x2e,0x32,0x30,0x30,0x30,0x30,
    0x30,0x30,0x34,0x37,0x36,0x38,0x33,0x37,0x31,0x35,0x38,0x32,0x30,0x33,0x31,0x32,
    0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x62,0x6f,0x6f,0x6c,0x20,0x5f,0x31,0x37,0x31,
    0x20,0x3d,0x20,0x5f,0x35,0x32,0x2e,0x78,0x20,0x3c,0x20,0x30,0x2e,0x30,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x62,0x6f,0x6f,0x6c,0x20,0x5f,0x31,0x37,0x38,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x21,0x5f,0x31,0x37,0x31,0x29,0x0a,0x20,0x20,
    0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x31,0x37,0x38,
    0x20,0x3d,0x20,0x5f,0x35,0x32,0x2e,0x78,0x20,0x3e,0x20,0x31,0x2e,0x30,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x65,0x6c,0x73,0x65,0x0a,0x20,
    0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x31,0x37,
    0x38,0x20,0x3d,0x20,0x5f,0x31,0x37,0x31,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,
    0x20,0x20,0x20,0x20,0x62,0x6f,0x6f,0x6c,0x20,0x5f,0x31,0x38,0x35,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x21,0x5f,0x31,0x37,0x38,0x29,0x0a,0x20,0x20,
    0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x31,0x38,0x35,
    0x20,0x3d,0x20,0x5f,0x35,0x32,0x2e,0x79,0x20,0x3c,0x20,0x30,0x2e,0x30,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x65,0x6c,0x73,0x65,0x0a,0x20,
    0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x31,0x38,
    0x35,0x20,0x3d,0x20,0x5f,0x31,0x37,0x38,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,
    0x20,0x20,0x20,0x20,0x62,0x6f,0x6f,0x6c,0x20,0x5f,0x31,0x39,0x32,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x21,0x5f,0x31,0x38,0x35,0x29,0x0a,0x20,0x20,
    0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x31,0x39,0x32,
    0x20,0x3d,0x20,0x5f,0x35,0x32,0x2e,0x79,0x20,0x3e,0x20,0x31,0x2e,0x30,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x65,0x6c,0x73,0x65,0x0a,0x20,
    0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x31,0x39,
    0x32,0x20,0x3d,0x20,0x5f,0x31,0x38,0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,
    0x20,0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x5f,0x31,0x39,0x32,0x29,0x0a,0x20,0x20,
    0x20,0x20,0x7b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x36,0x39,0x20,0x22,0x22,0x0a,
    0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,
    0x66,0x6c,0x6f,0x61,0x74,0x33,0x28,0x30,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x7d,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x37,0x32,0x20,0x22,0x22,0x0a,0x20,
    0x20,0x20,0x20,0x6f,0x75,0x74,0x2e,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,
    0x72,0x20,0x3d,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x28,0x63,0x6f,0x6c,0x6f,0x72,
    0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,
    0x72,0x6e,0x20,0x6f,0x75,0x74,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#if !defined(SOKOL_GFX_INCLUDED)
  #error "Please include sokol_gfx.h before dot_click.glsl.h"
#endif
static inline const sg_shader_desc* crt_shader_desc(void) {
  if (sg_query_backend() == SG_BACKEND_METAL_MACOS) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.vs.source = vs_source_metal_macos;
      desc.vs.entry = "main0";
      desc.fs.source = crt_fs_source_metal_macos;
      desc.fs.entry = "main0";
      desc.fs.images[0].name = "tex";
      desc.fs.images[0].type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "crt_shader";
    };
    return &desc;
  }
  return 0;
}
static inline const sg_shader_desc* dot_click_shader_desc(void) {
  if (sg_query_backend() == SG_BACKEND_METAL_MACOS) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.vs.source = vs_source_metal_macos;
      desc.vs.entry = "main0";
      desc.fs.source = fs_source_metal_macos;
      desc.fs.entry = "main0";
      desc.fs.images[0].name = "tex";
      desc.fs.images[0].type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "dot_click_shader";
    };
    return &desc;
  }
  return 0;
}
