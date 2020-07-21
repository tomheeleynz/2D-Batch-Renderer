//
//  MetalVertexArray.swift
//  ArcEngine
//
//  Created by Thomas Heeley on 18/06/20.
//

import Foundation
import Cocoa
import MetalKit

class SwiftVertexArray : NSObject
{
    var vertexDescriptor : MTLVertexDescriptor!
    var pipelineState : MTLRenderPipelineState!
    var m_Shader : SwiftShader!
    var m_VertexBuffer : SwiftVertexBuffer!
    var m_IndexBuffer : SwiftIndexBuffer!
    
    override init() {
        vertexDescriptor = MTLVertexDescriptor()
        
        // Position
        vertexDescriptor.attributes[0].format = .float3
        vertexDescriptor.attributes[0].bufferIndex = 0
        vertexDescriptor.attributes[0].offset = 0
        
        // Color
        vertexDescriptor.attributes[1].format = .float3
        vertexDescriptor.attributes[1].bufferIndex = 0
        vertexDescriptor.attributes[1].offset = (MemoryLayout<Float>.stride) * 3
        
        // Texture
        vertexDescriptor.attributes[2].format = .float2
        vertexDescriptor.attributes[2].bufferIndex = 0
        vertexDescriptor.attributes[2].offset = (MemoryLayout<Float>.stride) * 6
        
        // Overall Stride of Vertex Array
        vertexDescriptor.layouts[0].stride = MemoryLayout<Vertex>.stride
    }
    
    @objc func Bind(_ device : MTLDevice, _ context : MTKView) {
        
        // Creating Pipeline
        let pipelineDescriptor = MTLRenderPipelineDescriptor()
        pipelineDescriptor.vertexFunction = m_Shader.GetVertexFunction()
        pipelineDescriptor.fragmentFunction = m_Shader.GetFragmentFunction()
        pipelineDescriptor.vertexDescriptor = vertexDescriptor
        pipelineDescriptor.colorAttachments[0].pixelFormat = context.colorPixelFormat
        pipelineDescriptor.colorAttachments[0].isBlendingEnabled = true
        pipelineDescriptor.colorAttachments[0].rgbBlendOperation = MTLBlendOperation.add
        pipelineDescriptor.colorAttachments[0].alphaBlendOperation = MTLBlendOperation.add
        pipelineDescriptor.colorAttachments[0].sourceRGBBlendFactor = MTLBlendFactor.sourceAlpha
        pipelineDescriptor.colorAttachments[0].sourceAlphaBlendFactor = MTLBlendFactor.sourceAlpha
        pipelineDescriptor.colorAttachments[0].destinationRGBBlendFactor = MTLBlendFactor.oneMinusSourceAlpha
        pipelineDescriptor.colorAttachments[0].destinationAlphaBlendFactor = MTLBlendFactor.oneMinusSourceAlpha
        
        do {
            pipelineState = try device.makeRenderPipelineState(descriptor: pipelineDescriptor)
        }
        catch let error {
            fatalError(error.localizedDescription)
        }
    }
    
    @objc func GetVertexDescriptor() -> MTLVertexDescriptor
    {
        return vertexDescriptor
    }
    
    @objc func GetPipeline() -> MTLRenderPipelineState
    {
        return pipelineState
    }
    
    // Setting and Getting Vertex Buffer
    @objc func GetVertexBuffer()->MTLBuffer {
        return m_VertexBuffer.GetVertexBuffer()
    }
    
    @objc func AddVertexBuffer(_ vertexBuffer : SwiftVertexBuffer) {
        m_VertexBuffer = vertexBuffer
    }
    
    // Setting and Getting Index Buffer
    @objc func GetIndexBuffer()->MTLBuffer {
        return m_IndexBuffer.GetIndexBuffer()
    }
   
    @objc func AddIndexBuffer(_ IndexBuffer : SwiftIndexBuffer) {
        m_IndexBuffer = IndexBuffer
    }
    
    // Setting Shader
    @objc func AddShader(_ shader : SwiftShader)
    {
        m_Shader = shader
    }
}
