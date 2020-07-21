//
//  MetalTexture.swift
//  ArcEngine
//
//  Created by Thomas Heeley on 17/07/20.
//

import Cocoa
import MetalKit

class SwiftTexture : NSObject
{
    static var m_textureLoader : MTKTextureLoader!
    var m_strFileName : URL!
    var m_texture : MTLTexture!
    
    @objc init(_ _strFileName : URL, _ device : MTLDevice)
    {
        SwiftTexture.m_textureLoader = MTKTextureLoader(device: device);
        
        let textureLoaderOptions :[MTKTextureLoader.Option : Any] = [.origin: MTKTextureLoader.Origin.flippedVertically]
        
        do {
            m_texture = try SwiftTexture.m_textureLoader.newTexture(URL: _strFileName, options: textureLoaderOptions)
            print("Texture Created")
        } catch let error {
            print(error.localizedDescription)
        }
    }
    
    @objc func GetNative()->MTLTexture {
        return m_texture;
    }
}
