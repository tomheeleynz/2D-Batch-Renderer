#pragma once
#include "Arc/Renderer/GraphicsContext.h"
#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/Shader.h"
#include "Arc/Renderer/Texture.h"

namespace Arc
{
	class RenderAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1,
			Metal = 2,
			Vulkan = 3
		};

	public:
        virtual ~RenderAPI() = default;
		
        virtual void Init() = 0;
		virtual void SetViewport(int x, int y, int width, int height) = 0;
		virtual void SetClearColor(float x, float y, float z) = 0;
		virtual void Clear() = 0;
        virtual void* GetDevice() = 0;
        
		virtual void SetContext(GraphicsContext* _context) = 0;
        
		virtual void DrawIndexedPrimative(VertexArray* _pVertexArray, unsigned int count = 0) = 0;
		virtual void DrawPrimative(VertexArray* _pVertexArray, unsigned int count = 0) = 0;
        
        virtual void BindTexture(Texture* texture) = 0;

		static API GetAPI() { return s_API; };
		static RenderAPI* Create();
	private:
		static API s_API;
	};
}
