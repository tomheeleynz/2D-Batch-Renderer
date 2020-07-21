#include "OpenGLRenderAPI.h"
#include <glad/glad.h>

namespace Arc
{
    OpenGLRenderAPI::OpenGLRenderAPI()
    {
        
    }

	void OpenGLRenderAPI::Init()
	{
		glEnable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRenderAPI::SetViewport(int x, int y, int width, int height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRenderAPI::SetClearColor(float x, float y, float z)
	{
		glClearColor(x, y, z, 1.0f);
	}

	void OpenGLRenderAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRenderAPI::DrawIndexedPrimative(VertexArray* _pVertexArray, unsigned int count)
	{
		unsigned int indexCount = _pVertexArray->GetIndexBuffer()->GetCount();
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
	}

	void OpenGLRenderAPI::DrawPrimative(VertexArray* _pVertexArray, unsigned int count)
	{
		glDrawArrays(GL_TRIANGLES, 0, count);
	}

	void OpenGLRenderAPI::SetContext(GraphicsContext* _context)
	{
		m_Context = _context;
	}

	void* OpenGLRenderAPI::GetDevice()
	{
		return nullptr;
	}

    void OpenGLRenderAPI::BindTexture(Texture* texture)
    {
        
    }
}
