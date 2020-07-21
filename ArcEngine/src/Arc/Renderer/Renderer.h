#pragma once

#include "Arc/Renderer/GraphicsContext.h"
#include "Arc/Renderer/RenderCommand.h"
#include "Arc/Renderer/VertexArray.h"

namespace Arc
{
	class Renderer
	{
	public:
		static void Init(GraphicsContext* _context = nullptr);
		static void Clear();
		static void ClearColor(float x, float y, float z);
		static void DrawIndexedPrimative(VertexArray* _pVertexArray, Shader* _pShader, unsigned int count = 0);
		static void DrawPrimative(VertexArray* _pVertexArray, Shader* _pShader, unsigned int count = 0);
		static void Submit(VertexArray* _pVertexArray, Shader* _pShader);
		static void* GetDevice();

		static RenderAPI::API GetApi();
	private:

	};
}
