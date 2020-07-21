#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Arc
{
	class Shader
	{
	public:
		virtual ~Shader() = default;


		virtual void Bind() = 0;
		virtual void Unbind() = 0;
        virtual void* GetNative() = 0;

		// Uniform Things
		virtual void SetInt(std::string uniformName, int uniformValue) = 0;
		virtual void SetMat4(std::string uniformName, glm::mat4 uniformValue) = 0;

		static Shader* Create(const char* vertexSrc, const char* fragmentSrc);
		static Shader* Create(std::string filepath);
	private:

	};
}
