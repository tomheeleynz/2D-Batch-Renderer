#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdint.h>

namespace Arc
{
    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 texture;
    };

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual unsigned int GetCount() = 0;
        virtual void* GetNative() = 0;

		static IndexBuffer* Create(uint32_t* indices, int size);
	private:

	};

	class VertexBuffer
	{
	public:
	
		virtual ~VertexBuffer();

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
        virtual void SetData(void* data, int size) = 0;
        virtual void* GetNative() = 0;
        
		static VertexBuffer* Create(Vertex* vertices, int size);
        static VertexBuffer* Create(int size);
	private:

	};
}
