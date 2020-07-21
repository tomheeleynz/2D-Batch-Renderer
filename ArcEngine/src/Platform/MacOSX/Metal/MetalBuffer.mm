//
//  MetalVertexBuffer.m
//  ArcEngine
//
//  Created by Thomas Heeley on 22/05/20.
//

#include "MetalBuffer.h"
#include "Arc/Renderer/Renderer.h"
#import  <Cocoa/Cocoa.h>
#import  <MetalKit/MetalKit.h>
#import  <Appkit/AppKit.h>
// Has To Come After Other Swift Includes
#import  <ArcEngine-Swift.h>

namespace Arc
{
    //---------------------------------
    //---------Vertex Buffer-----------
    //---------------------------------
    struct MetalVertexBuffer::Impl
    {
        SwiftVertexBuffer* m_Buffer;
    };

    MetalVertexBuffer::MetalVertexBuffer(Vertex* vertices, int size) : impl(new Impl)
    {
        impl->m_Buffer = [[SwiftVertexBuffer alloc] init:(id<MTLDevice>)Renderer::GetDevice() :(void*)vertices :(NSInteger)size];
    }

    MetalVertexBuffer::MetalVertexBuffer(int size) : impl(new Impl)
    {
        impl->m_Buffer = [[SwiftVertexBuffer alloc] init:(id<MTLDevice>)Renderer::GetDevice() :(NSInteger)size];
    }

    void MetalVertexBuffer::Bind()
    {
        
    }
    
    void MetalVertexBuffer::Unbind()
    {
        
    }

    void* MetalVertexBuffer::GetNative()
    {
        return (void*)impl->m_Buffer;
    }

    void MetalVertexBuffer::SetData(void *data, int size)
    {
        [impl->m_Buffer SetData:(id<MTLDevice>)Renderer::GetDevice() :data :(NSInteger)size];
    }

    //---------------------------------
    //---------Index Buffer------------
    //---------------------------------
    struct MetalIndexBuffer::Impl
    {
        SwiftIndexBuffer* m_Buffer;
    };

    MetalIndexBuffer::MetalIndexBuffer(uint32_t* indices, int size) : impl(new Impl), m_iCount(size)
    {
        impl->m_Buffer = [[SwiftIndexBuffer alloc] init:(id<MTLDevice>)Renderer::GetDevice() :(void*)indices :(NSInteger)size];
    }

    void MetalIndexBuffer::Bind()
    {
        
    }

    void MetalIndexBuffer::Unbind()
    {
        
    }
    
    void* MetalIndexBuffer::GetNative()
    {
        return (void*)impl->m_Buffer;
    }
    
    unsigned int MetalIndexBuffer::GetCount()
    {
        return m_iCount;
    }
}
