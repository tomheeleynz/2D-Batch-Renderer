#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/Renderer2D.h"

namespace Arc
{
	void Renderer::Init(GraphicsContext* _context)
	{
		RenderCommand::Init(_context);
        Renderer2D::Init();
	}

	void Renderer::Clear()
	{
		RenderCommand::Clear();
	}

	void Renderer::ClearColor(float x, float y, float z)
	{
		RenderCommand::ClearColor(x, y, z);
	}

	RenderAPI::API Renderer::GetApi()
	{
		return RenderAPI::GetAPI();
	}

	void Renderer::Submit(VertexArray* _pVertexArray, Shader* _pShader)
	{
	
	}

	void Renderer::DrawIndexedPrimative(VertexArray* _pVertexArray, Shader* _pShader, unsigned int count)
	{
    #ifdef ARC_PLATFORM_WINDOWS
        _pShader->Bind();
        _pVertexArray->Bind();
    #endif
           
    #ifdef ARC_PLATFORM_MACOSX
        _pVertexArray->AddShader(_pShader);
    #endif
		RenderCommand::DrawIndexedPrimative(_pVertexArray, count);
	}
	
	void Renderer::DrawPrimative(VertexArray* _pVertexArray, Shader* _pShader, unsigned int count)
	{
    #ifdef ARC_PLATFORM_WINDOWS
        _pShader->Bind();
        _pVertexArray->Bind();
    #endif
    
    #ifdef ARC_PLATFORM_MACOSX
        _pVertexArray->AddShader(_pShader);
    #endif
        
		RenderCommand::DrawPrimative(_pVertexArray, count);
	}

	void* Renderer::GetDevice()
	{
		return RenderCommand::GetDevice();
	}

}
