//
//  MetalTexture.h
//  ArcEngine
//
//  Created by Thomas Heeley on 17/07/20.
//

#ifndef MetalTexture_h
#define MetalTexture_h

#include <string>
#include "Arc/Renderer/Texture.h"

namespace Arc
{
    class MetalTexture : public Texture
    {
    public:
        MetalTexture(std::string _strFileName);
        
        int GetWidth() override;
        int GetHeight() override;
        
        void* GetNative() override;
        void Bind(uint32_t slot = 0) override;
    private:
        struct Impl;
        Impl* impl;
        
    };
}

#endif /* MetalTexture_h */
