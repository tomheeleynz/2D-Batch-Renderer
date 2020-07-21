//
//  MetalGraphicsContext.h
//  ArcEngine
//
//  Created by Thomas Heeley on 14/06/20.
//

#ifndef MetalGraphicsContext_h
#define MetalGraphicsContext_h

#include "Arc/Renderer/GraphicsContext.h"

namespace Arc {
    class MetalGraphicsContext : public GraphicsContext
    {
    public:
        MetalGraphicsContext(void* windowHandle);
        void Init() override;
        void* GetNative() override;
    private:
        struct Impl;
        Impl* impl;
    };
}

#endif /* MetalGraphicsContext_h */
