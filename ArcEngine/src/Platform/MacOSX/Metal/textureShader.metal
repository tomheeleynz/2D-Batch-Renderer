//
//  textureShader.metal
//  ArcEngine
//
//  Created by Thomas Heeley on 18/07/20.
//

#include <metal_stdlib>
using namespace metal;

struct VertexIn {
    float3 position [[attribute(0)]];
    float3 color    [[attribute(1)]];
    float2 texture  [[attribute(2)]];
};

struct VertexOut {
    float4 position [[position]];
    float4 color;
    float2 texture;
};

vertex VertexOut vertex_main(VertexIn in [[stage_in]]) {
    VertexOut out;
    out.position = float4(in.position, 1);
    out.color = float4(in.color, 1);
    out.texture = in.texture;
    return out;
}

fragment float4 fragment_main(VertexOut in [[stage_in]], texture2d<float> colorTexture [[texture(1)]]) {
    constexpr sampler textureSampler;
    return colorTexture.sample(textureSampler, in.texture);
}
