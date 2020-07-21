//
//  MetalShader.m
//  ArcEngine
//
//  Created by Thomas Heeley on 25/05/20.
//

#include "MetalShader.h"
#include <iostream>
#include <string>
#include "Arc/Renderer/Renderer.h"

// OBJC Import Stuff
#import  <Cocoa/Cocoa.h>
#import  <MetalKit/MetalKit.h>
#import  <Appkit/AppKit.h>
#import   <simd/simd.h>
// Has To Come After Other Swift Includes
#import  <ArcEngine-Swift.h>

namespace Arc
{
    struct MetalShader::Impl
    {
        SwiftShader* m_Shader;
        id<MTLDevice> device;
        NSString* fileName;
        NSURL* fileURL;
    };
    
    MetalShader::MetalShader(std::string _strFileName) : impl(new Impl)
    {
        impl->fileName = [NSString stringWithCString:_strFileName.c_str() encoding:[NSString defaultCStringEncoding]];
        impl->fileURL = [NSURL fileURLWithPath:impl->fileName];
        
        // Getting File name and directories to build shader Location
        std::string fileName = [[[impl->fileURL URLByDeletingPathExtension] lastPathComponent] UTF8String];
        std::string fileDirectory = [[[impl->fileURL URLByDeletingLastPathComponent] path] UTF8String];
        fileDirectory = fileDirectory + "/";
        
        // Creating Lib File String
        std::string libFile = fileDirectory + fileName + ".metallib";
        
        std::string command = "/Users/thomasheeley/Desktop/ArcEngine/ArcEngine/src/Platform/MacOSX/Metal/CreateShader.sh " + fileDirectory + " " + fileName;

        system(command.c_str());
        impl->device = (id<MTLDevice>)Renderer::GetDevice();
        impl->m_Shader = [[SwiftShader alloc] init];
        [impl->m_Shader CreateShader:impl->device :[NSString stringWithCString:libFile.c_str() encoding:[NSString defaultCStringEncoding]]];
    }
    
    void MetalShader::Bind()
    {
        
    }
    
    void MetalShader::Unbind()
    {
        
    }
    
    void* MetalShader::GetNative()
    {
        return(void*)impl->m_Shader;
    }

    void MetalShader::SetInt(std::string uniformName, int value)
    {
        
    }

    void MetalShader::SetMat4(std::string uniformName, glm::mat4 value)
    {
        
    }
}
