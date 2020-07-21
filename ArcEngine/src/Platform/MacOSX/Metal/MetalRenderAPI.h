//
//  MetalRenderAPI.h
//  ArcEngine
//
//  Created by Thomas Heeley on 14/06/20.
//

#ifndef MetalRenderAPI_h
#define MetalRenderAPI_h

#include "Arc/Renderer/RenderAPI.h"

namespace Arc
{
    class MetalRenderAPI : public RenderAPI
    {
    public:
        MetalRenderAPI();
        void Init() override;
        void SetClearColor(float x, float y, float z) override;
        void Clear() override;
        void SetViewport(int x, int y, int width, int height) override;
        
        void SetContext(GraphicsContext* _context) override;
        void DrawIndexedPrimative(VertexArray* _pVertexArray, unsigned int count = 0) override;
        void DrawPrimative(VertexArray* _pVertexArray, unsigned int count = 0) override;
        void* GetDevice() override;
        void BindTexture(Texture* texture) override;
    
    private:
        GraphicsContext* m_Context;
        struct Impl;
        Impl* impl;
    };
}

#endif /* MetalRenderAPI_h */
