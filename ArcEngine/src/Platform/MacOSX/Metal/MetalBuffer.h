//
//  MetalVertexBuffer.h
//  ArcEngine
//
//  Created by Thomas Heeley on 22/05/20.
//

#ifndef MetalVertexBuffer_h
#define MetalVertexBuffer_h
#include <iostream>
#include "Arc/Renderer/Buffer.h"

namespace Arc
{
    class MetalVertexBuffer : public VertexBuffer
    {
    public:
        MetalVertexBuffer(Vertex* vertices, int size);
        MetalVertexBuffer(int size);
        
        void Bind() override;
        void Unbind() override;
        void* GetNative() override;
        void SetData(void* data, int size) override;
    private:
        struct Impl;
        Impl* impl;
    };

    class MetalIndexBuffer : public IndexBuffer
    {
    public:
        MetalIndexBuffer(uint32_t* indices, int size);
        void Bind() override;
        void Unbind() override;
        void* GetNative() override;
        unsigned int GetCount() override;
    private:
        int m_iCount;
        struct Impl;
        Impl* impl;
    };
}

#endif /* MetalVertexBuffer_h */
