//
//  MetalGraphicsContext.m
//  ArcEngine
//
//  Created by Thomas Heeley on 14/06/20.
//

#include "Platform/MacOSX/Metal/MetalGraphicsContext.h"
#include <iostream>
#include <string>

// OBJC Import Stuff
#import  <Cocoa/Cocoa.h>
#import  <MetalKit/MetalKit.h>
#import  <Appkit/AppKit.h>
// Has To Come After Other Swift Includes
#import  <ArcEngine-Swift.h>


namespace Arc
{
    struct MetalGraphicsContext::Impl
    {
        ViewController* m_ViewController;
        MTKView* context;
        Window* m_WindowHandle;
        Renderer* m_Renderer;
    };

    MetalGraphicsContext::MetalGraphicsContext(void* windowHandle) : impl(new Impl)
    {
        impl->m_WindowHandle = (Window*)windowHandle;
    }

    void MetalGraphicsContext::Init()
    {
        impl->m_ViewController = [[ViewController alloc] init];
        [impl->m_ViewController loadView];
        impl->context = (MTKView*)[impl->m_ViewController GetView];
        [impl->m_WindowHandle MakeContextCurrent:impl->m_ViewController];
    }

    void* MetalGraphicsContext::GetNative()
    {
        return(void*)impl->context;
    }
}
