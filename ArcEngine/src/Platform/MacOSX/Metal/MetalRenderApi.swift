import MetalKit
import simd

class Renderer: NSObject {
    static var device: MTLDevice!
    static var commandQueue: MTLCommandQueue!
    var vertexBuffer: MTLBuffer!
    var indexBuffer: MTLBuffer!
    var primativeType: MTLPrimitiveType!
    var indexCount: Int!
    var pipelineState: MTLRenderPipelineState!
    var currentTexture : MTLTexture!
    
    var drawIndexed : Bool = false
    var verticesCount : Int = 0
    
    // Clear Color Values
    var clearR : Double = 0.2
    var clearB : Double = 0.3
    var clearG : Double = 0.3
    
    @objc func GetDevice()->MTLDevice
    {
        return Renderer.device
    }
    
    @objc func SetVertexCount(_ count : Int) {
        verticesCount = count
    }
    
    @objc func SetIndexCount(_ count : Int) {
        indexCount = count
    }
    
    @objc func SetClearColor(_ red : Double, _ green : Double, _ blue : Double)->Void {
        clearR = red
        clearG = green
        clearB = blue
    }
    
    @objc func SetVertexArray(_ state : SwiftVertexArray, _ indexed : Bool) {
        pipelineState = state.GetPipeline()
        vertexBuffer = state.GetVertexBuffer()
        
        if (indexed == true) {
            indexBuffer = state.GetIndexBuffer()
            drawIndexed = indexed
        }
    }
    
    @objc func BindTexture(_ texture : MTLTexture)
    {
        currentTexture = texture
    }
    
    @objc init(metalView: MTKView) {
        guard let device = MTLCreateSystemDefaultDevice(), let commandQueue = device.makeCommandQueue() else {
            fatalError("GPU not available")
        }
                
        Renderer.device = device
        Renderer.commandQueue = commandQueue
    
        metalView.device = device
        
        super.init()
        
        metalView.delegate = self
    }
}

extension Renderer: MTKViewDelegate {
    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {
        
    }
    
    func draw(in view: MTKView) {
        guard let commandBuffer = Renderer.commandQueue.makeCommandBuffer() else {return}
        guard let renderPassDescriptor = view.currentRenderPassDescriptor else {return}
        
        renderPassDescriptor.colorAttachments[0].clearColor = MTLClearColorMake(clearR, clearG, clearB, 1.0)
        
        guard let renderEncoder = commandBuffer.makeRenderCommandEncoder(descriptor: renderPassDescriptor) else {return}
        
        renderEncoder.setRenderPipelineState(pipelineState)
        
        // Draw Here
        renderEncoder.setVertexBuffer(vertexBuffer, offset: 0, index: 0)
        
        if (currentTexture != nil) {
            renderEncoder.setFragmentTexture(currentTexture, index: 1)
        }
        
        if (drawIndexed == false) {
            renderEncoder.drawPrimitives(type: .triangle, vertexStart: 0, vertexCount: verticesCount)
        }
        else {
            renderEncoder.drawIndexedPrimitives(type: .triangle, indexCount: indexCount, indexType: .uint32, indexBuffer: indexBuffer, indexBufferOffset: 0)
        }
       
        renderEncoder.endEncoding()
        
        guard let drawable = view.currentDrawable else {
            return
        }
        
        commandBuffer.present(drawable)
        commandBuffer.commit()
    }
}

