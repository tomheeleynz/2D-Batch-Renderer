#pragma once
#include <memory>
#include "Arc/Renderer/GraphicsContext.h"
#include "Arc/Renderer/RenderAPI.h"
#include "Arc/Renderer/VertexArray.h"

namespace Arc
{
	class RenderCommand
	{
	public:
		static void Init(GraphicsContext* _context = nullptr);
		static void ClearColor(float x, float y, float z);
		static void Clear();
		static void DrawIndexedPrimative(VertexArray* _pVertexArray, unsigned int count = 0);
		static void DrawPrimative(VertexArray* _pVertexArray, unsigned int count = 0);
		static void* GetDevice();
        static void BindTexture(Texture* texture);
	private:
		static std::unique_ptr<RenderAPI> s_RendererAPI;
	};
}
