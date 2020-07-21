//
//  Use this file to import your target's public headers that you would like to expose to Swift.
//

#import <simd/simd.h>

struct Vertex
{
    float position[3];
    float color[3];
    float texture[2];
};

typedef struct Vertex Vertex;

struct TriVertex
{
    simd_float3 position;
    simd_float3 color;
    simd_float2 texture;
};

typedef struct TriVertex TriVertex;
