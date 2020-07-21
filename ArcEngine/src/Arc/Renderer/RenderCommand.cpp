#include "RenderCommand.h"

namespace Arc
{
	std::unique_ptr<RenderAPI> RenderCommand::s_RendererAPI = std::unique_ptr<RenderAPI>(RenderAPI::Create());

	void RenderCommand::Init(GraphicsContext* _context)
	{
        s_RendererAPI->SetContext(_context);
		s_RendererAPI->Init();
	}	 
		 
	void RenderCommand::ClearColor(float x, float y, float z)
	{	
		s_RendererAPI->SetClearColor(x, y, z);
	}	 
		 
	void RenderCommand::Clear()
	{
		s_RendererAPI->Clear();
	}

	void RenderCommand::DrawIndexedPrimative(VertexArray* _pVertexArray, unsigned int count)
	{
		s_RendererAPI->DrawIndexedPrimative(_pVertexArray, count);
	}

	void RenderCommand::DrawPrimative(VertexArray* _pVertexArray, unsigned int count)
	{
		s_RendererAPI->DrawPrimative(_pVertexArray, count);
	}
    
    void* RenderCommand::GetDevice()
    {
        return s_RendererAPI->GetDevice();
    }

    void RenderCommand::BindTexture(Texture* texture)
    {
        s_RendererAPI->BindTexture(texture);
    }
}
