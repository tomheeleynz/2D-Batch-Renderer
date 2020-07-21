#pragma once

#include "Arc/Renderer/Buffer.h"
#include "Arc/Renderer/Shader.h"

namespace Arc
{
	class VertexArray
	{
	public:
		virtual void Unbind() = 0;
		virtual void Bind() = 0;

		virtual void AddVertexBuffer(VertexBuffer* _pBuffer) = 0;
		virtual void SetIndexBuffer(IndexBuffer* _pBuffer) = 0;
        virtual void AddShader(Shader* _pShader) = 0;
        virtual void* GetNative() = 0;
		virtual IndexBuffer* GetIndexBuffer() = 0;

		static VertexArray* Create();
	private:

	};
}
