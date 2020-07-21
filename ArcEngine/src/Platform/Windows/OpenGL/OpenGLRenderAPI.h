#pragma once

#include "Arc/Renderer/RenderAPI.h"

namespace Arc
{
	class OpenGLRenderAPI : public RenderAPI
	{
	public:
        OpenGLRenderAPI();

		virtual void Init() override;
		virtual void SetViewport(int x, int y, int width, int height) override;
		virtual void SetClearColor(float x, float y, float z) override;
		virtual void Clear() override;
		
		void SetContext(GraphicsContext* _context) override;

		virtual void DrawIndexedPrimative(VertexArray* _pVertexArray, unsigned int count = 0) override;
		virtual void DrawPrimative(VertexArray* _pVertexArray, unsigned int count = 0) override;

		virtual void* GetDevice() override;
        void BindTexture(Texture* texture) override;
	private:
		GraphicsContext* m_Context;

	};
}
