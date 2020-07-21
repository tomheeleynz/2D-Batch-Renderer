//
//  VertexBuffer.swift
//  ArcEngine
//
//  Created by Thomas Heeley on 22/05/20.
//

import Foundation
import MetalKit

class SwiftVertexBuffer : NSObject
{
    var vertexBuffer : MTLBuffer!
    var testVertexStuff : UnsafePointer<Vertex>!
    
    override init() {
        
    }
    
    @objc init(_ device : MTLDevice, _ data : UnsafeRawPointer, _ size : Int) {
        let vertexData = data.assumingMemoryBound(to: Vertex.self)
        let vertexSize = MemoryLayout<Vertex>.stride * size
        self.vertexBuffer = device.makeBuffer(bytes: vertexData, length: vertexSize, options: [])
    
    }
    
    @objc init(_ device : MTLDevice, _ size : Int) {
        let vertexSize = MemoryLayout<Vertex>.stride * size
        self.vertexBuffer = device.makeBuffer(length: vertexSize, options: [])
    }
    
    @objc func GetVertexBuffer()->MTLBuffer {
        return vertexBuffer
    }
    
    @objc func SetData(_ device : MTLDevice, _ data : UnsafeRawPointer, _ size : Int)->Void {
        testVertexStuff = data.assumingMemoryBound(to: Vertex.self)
        let vertexSize = MemoryLayout<Vertex>.stride * size
        self.vertexBuffer = device.makeBuffer(bytes: testVertexStuff, length: vertexSize, options: [])
    }
}

class SwiftIndexBuffer : NSObject
{
    var indexBuffer : MTLBuffer!
    
    override init() {
        
    }
    
    @objc init(_ device : MTLDevice, _ data : UnsafeRawPointer, _ count : Int) {
        let indexData = data.assumingMemoryBound(to: uint.self)
        let indexBufferSize = MemoryLayout<uint>.stride * count
        self.indexBuffer = device.makeBuffer(bytes: indexData, length: indexBufferSize, options: [])
    }
    
    @objc func GetIndexBuffer()->MTLBuffer {
        return indexBuffer
    }

}
