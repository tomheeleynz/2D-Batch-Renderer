#include "Platform/Windows/OpenGL/OpenGLVertexArray.h"
#include <glad/glad.h>
#include <iostream>

namespace Arc
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &m_iVAO);
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(m_iVAO);
	}

	void OpenGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(VertexBuffer* _pBuffer)
	{
		glBindVertexArray(m_iVAO);
		_pBuffer->Bind();
		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);
	
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, color)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, texture)));
		glEnableVertexAttribArray(2);

		glBindVertexArray(0);
		_pBuffer->Unbind();
        
        m_pVertexBuffer = _pBuffer;
	}

	void OpenGLVertexArray::SetIndexBuffer(IndexBuffer* _pBuffer)
	{
		glBindVertexArray(m_iVAO);
		_pBuffer->Bind();
		glBindVertexArray(0);
		_pBuffer->Unbind();
		m_pIndexBuffer = _pBuffer;
	}

	IndexBuffer* OpenGLVertexArray::GetIndexBuffer()
	{
		return m_pIndexBuffer;
	}

	void OpenGLVertexArray::AddShader(Shader* _pShader)
	{
		m_pShader = _pShader;
	}

	void* OpenGLVertexArray::GetNative()
	{
		return (void*)m_iVAO;
	}

}
