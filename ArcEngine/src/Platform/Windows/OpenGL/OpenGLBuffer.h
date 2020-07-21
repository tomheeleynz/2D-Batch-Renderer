#pragma once

#include "Arc/Renderer/Buffer.h"

namespace Arc
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(Vertex* vertices, int size);
		OpenGLVertexBuffer(int size);

		virtual void Bind() override;
		virtual void Unbind() override;
		void* GetNative() override;
		void SetData(void* data, int size) override;

	private:
		unsigned int m_iVBO;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indices, int count);

		void Bind() override;
		void Unbind() override;
		void* GetNative() override;

		unsigned int GetCount() override;
	private:
		int m_iCount;
		unsigned m_iEBO;

	};
}
