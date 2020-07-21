//
//  MetalVertexArray.h
//  ArcEngine
//
//  Created by Thomas Heeley on 18/06/20.
//

#ifndef MetalVertexArray_h
#define MetalVertexArray_h

#include "Arc/Renderer/VertexArray.h"

namespace Arc
{
    class MetalVertexArray : public VertexArray
    {
    public:
        MetalVertexArray();
        void Bind() override;
        void Unbind() override;
        
        void AddVertexBuffer(VertexBuffer* _pBuffer) override;
        void SetIndexBuffer(IndexBuffer* _pBuffer) override;
        void AddShader(Shader* _pShader) override;
        void* GetNative() override;
        
        IndexBuffer* GetIndexBuffer() override;        
    private:
        VertexBuffer* m_pVertexBuffer;
        IndexBuffer* m_pIndexBuffer;
        Shader* m_pShader;
        
        // OBJC Implementation
        struct Impl;
        Impl* impl;
    };
}


#endif /* MetalVertexArray_h */
