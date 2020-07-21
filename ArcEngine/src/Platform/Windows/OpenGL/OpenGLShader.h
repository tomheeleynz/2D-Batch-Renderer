#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Arc/Renderer/Shader.h"

namespace Arc
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const char* vertexSrc, const char* fragmentSrc);
		OpenGLShader(std::string filepath);

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void* GetNative() override;

		// Uniforms
		void SetInt(std::string uniformName, int uniformValue) override;
		void SetMat4(std::string uniformName, glm::mat4 uniformValue) override; 

	private:
		unsigned int m_iShaderID;

	};
}
