#include "OpenGLBuffer.h"
#include <glad/glad.h>

namespace Arc
{
	//-------------------------------------
	//--------- Vertex Buffer--------------
	//-------------------------------------
	OpenGLVertexBuffer::OpenGLVertexBuffer(Vertex* vertices, int size)
	{
		glGenBuffers(1, &m_iVBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(Arc::Vertex), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(int size)
	{
		glGenBuffers(1, &m_iVBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
	}

	void OpenGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void* OpenGLVertexBuffer::GetNative()
	{
		return (void*)m_iVBO;
	}

	void OpenGLVertexBuffer::SetData(void* data, int size)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	//-------------------------------------
	//--------- Index Buffer---------------
	//-------------------------------------
	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* indices, int count) : m_iCount(count)
	{
		glGenBuffers(1, &m_iEBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, indices, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iEBO);
	}

	void OpenGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	unsigned int OpenGLIndexBuffer::GetCount()
	{
		return m_iCount;
	}

	void* OpenGLIndexBuffer::GetNative()
	{
		return (void*)m_iEBO;
	}
}
