//
//  MetalShader.swift
//  ArcEngine
//
//  Created by Thomas Heeley on 19/06/20.
//

import Foundation
import MetalKit

class SwiftShader : NSObject {
    var vertex_function : MTLFunction!
    var fragment_function : MTLFunction!
    var shaderLib : MTLLibrary!
    
    override init() {
        
    }
    
    @objc func CreateShader(_ device : MTLDevice, _ filepath : String)
    {
        do {
            print(filepath);
            let library = try device.makeLibrary(filepath: filepath)
            vertex_function = library.makeFunction(name: "vertex_main")
            fragment_function = library.makeFunction(name: "fragment_main")
        }
        catch let error {
            fatalError(error.localizedDescription)
        }
    }
    
    @objc func GetVertexFunction() -> MTLFunction
    {
        return vertex_function
    }
    
    @objc func GetFragmentFunction()->MTLFunction
    {
        return fragment_function
    }
}
