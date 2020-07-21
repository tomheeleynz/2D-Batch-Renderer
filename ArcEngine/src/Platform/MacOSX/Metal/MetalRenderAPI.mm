//
//  MetalRenderAPI.m
//  ArcEngine
//
//  Created by Thomas Heeley on 14/06/20.
//
#include "Platform/MacOSX/Metal/MetalRenderAPI.h"
#include "Platform/MacOSX/Metal/MetalGraphicsContext.h"

#include <iostream>

// OBJC Import Stuff
#import <simd/simd.h>
#import  <Cocoa/Cocoa.h>
#import  <MetalKit/MetalKit.h>
#import  <Appkit/AppKit.h>
// Has To Come After Other Swift Includes
#import  <ArcEngine-Swift.h>

namespace Arc
{
    struct MetalRenderAPI::Impl
    {
        Renderer* m_Renderer;     
    };
    
    MetalRenderAPI::MetalRenderAPI() : impl(new Impl)
    {
        
    }
    
    void MetalRenderAPI::Init()
    {
        MTKView* metalView = (MTKView*)static_cast<MetalGraphicsContext*>(m_Context)->GetNative();
        impl->m_Renderer = [[Renderer alloc] initWithMetalView:metalView];
    }
    
    void MetalRenderAPI::SetClearColor(float x, float y, float z)
    {
        [impl->m_Renderer SetClearColor:(double)x :(double)y :(double)z];
    }
    
    void MetalRenderAPI::Clear()
    {
        
    }
    
    void MetalRenderAPI::SetViewport(int x, int y, int width, int height)
    {
        
    }

    void MetalRenderAPI::SetContext(GraphicsContext* _context)
    {
        m_Context = _context;
    }
    
    void MetalRenderAPI::DrawIndexedPrimative(VertexArray *_pVertexArray, unsigned int count)
    {
        unsigned int indexCount = _pVertexArray->GetIndexBuffer()->GetCount();
        SwiftVertexArray* nativeVertexArray = (SwiftVertexArray*)_pVertexArray->GetNative();
        MTKView* metalView = (MTKView*)static_cast<MetalGraphicsContext*>(m_Context)->GetNative();
        id<MTLDevice> device = (id<MTLDevice>)GetDevice();
        [nativeVertexArray Bind:device :metalView];
        [impl->m_Renderer SetVertexArray:nativeVertexArray :true];
        [impl->m_Renderer SetIndexCount:(NSInteger)indexCount];
        [metalView draw];
    }

    void MetalRenderAPI::DrawPrimative(VertexArray *_pVertexArray, unsigned int count)
    {
        SwiftVertexArray* nativeVertexArray = (SwiftVertexArray*)_pVertexArray->GetNative();
        MTKView* metalView = (MTKView*)static_cast<MetalGraphicsContext*>(m_Context)->GetNative();
        id<MTLDevice> device = (id<MTLDevice>)GetDevice();
        [nativeVertexArray Bind:device :metalView];
        [impl->m_Renderer SetVertexCount:(NSInteger)count];
        [impl->m_Renderer SetVertexArray:nativeVertexArray :false];
        [metalView draw];
    }

    void* MetalRenderAPI::GetDevice()
    {
        return [impl->m_Renderer GetDevice];
    }

    void MetalRenderAPI::BindTexture(Texture *texture)
    {
        [impl->m_Renderer BindTexture:(id<MTLTexture>)texture->GetNative()];
    }
}
