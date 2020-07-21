//
//  MetalTexture.m
//  ArcEngine
//
//  Created by Thomas Heeley on 17/07/20.
//

#include "MetalTexture.h"
#include "Arc/Renderer/Renderer.h"

// OBJ-C Includes
#import  <Cocoa/Cocoa.h>
#import  <MetalKit/MetalKit.h>
#import  <Appkit/AppKit.h>
// Has To Come After Other Swift Includes
#import  <ArcEngine-Swift.h>

namespace Arc
{
    struct MetalTexture::Impl
    {
        SwiftTexture* m_Texture;
    };

    MetalTexture::MetalTexture(std::string _strFileName) : impl(new Impl)
    {
        // Converting to OBJ-C Types
        NSString* fileName = [NSString stringWithCString:_strFileName.c_str() encoding:[NSString defaultCStringEncoding]];
        NSURL* fileURL = [NSURL fileURLWithPath:fileName];
        impl->m_Texture = [[SwiftTexture alloc] init:fileURL :(id<MTLDevice>)Renderer::GetDevice()];
    }

    int MetalTexture::GetWidth()
    {
        
    }

    int MetalTexture::GetHeight()
    {
        
    }

    void MetalTexture::Bind(uint32_t slot)
    {
        RenderCommand::BindTexture(this);
    }

    void* MetalTexture::GetNative()
    {
        return [impl->m_Texture GetNative];
    }
}
