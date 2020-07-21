//
//  MetalVertexBuffer.m
//  ArcEngine
//
//  Created by Thomas Heeley on 18/06/20.
//

#include "MetalVertexArray.h"
#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/GraphicsContext.h"

// OBJC Import Stuff
#import  <Cocoa/Cocoa.h>
#import  <MetalKit/MetalKit.h>
#import  <Appkit/AppKit.h>
// Has To Come After Other Swift Includes
#import  <ArcEngine-Swift.h>

namespace Arc
{
    struct MetalVertexArray::Impl
    {
        SwiftVertexArray* m_swiftVertexArray;
    };
    
    MetalVertexArray::MetalVertexArray() : impl(new Impl)
    {
        impl->m_swiftVertexArray = [[SwiftVertexArray alloc] init];
    }

    void MetalVertexArray::Bind()
    {
        
    }

    void MetalVertexArray::Unbind()
    {
    
    }
    
    void* MetalVertexArray::GetNative()
    {
        return (void*)impl->m_swiftVertexArray;
    }

    void MetalVertexArray::AddVertexBuffer(VertexBuffer* _pBuffer)
    {
        SwiftVertexBuffer* buffer = (SwiftVertexBuffer*)_pBuffer->GetNative();
        [impl->m_swiftVertexArray AddVertexBuffer:buffer];
        m_pVertexBuffer = _pBuffer;
    }

    void MetalVertexArray::SetIndexBuffer(IndexBuffer *_pBuffer)
    {
        m_pIndexBuffer = _pBuffer;
        SwiftIndexBuffer* buffer = (SwiftIndexBuffer*)_pBuffer->GetNative();
        [impl->m_swiftVertexArray AddIndexBuffer:buffer];
    }

    IndexBuffer* MetalVertexArray::GetIndexBuffer()
    {
        return m_pIndexBuffer;
    }

    void MetalVertexArray::AddShader(Shader *_pShader)
    {
        SwiftShader* shader = (SwiftShader*)_pShader->GetNative();
        [impl->m_swiftVertexArray AddShader:shader];
        m_pShader = _pShader;
    }
}
