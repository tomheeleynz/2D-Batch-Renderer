#pragma once
#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/Shader.h"

namespace Arc
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();

		void Bind() override;
		void Unbind() override;
		void AddVertexBuffer(VertexBuffer* _pBuffer) override;
		void SetIndexBuffer(IndexBuffer* _pBuffer) override;
		void AddShader(Shader* _pShader) override;
		void* GetNative() override;
		IndexBuffer* GetIndexBuffer() override;

	private:
		unsigned int m_iVAO;
		IndexBuffer* m_pIndexBuffer;
        VertexBuffer* m_pVertexBuffer;
		Shader* m_pShader;
	};
}
