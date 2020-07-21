#include "OpenGLShader.h"
#include <glad/glad.h>

namespace Arc
{
	OpenGLShader::OpenGLShader(const char* vertexSrc, const char* fragmentSrc)
	{
		std::cout << vertexSrc << std::endl;
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
		glCompileShader(vertexShader);

		int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
		glCompileShader(fragmentShader);

		m_iShaderID = glCreateProgram();
		glAttachShader(m_iShaderID, vertexShader);
		glAttachShader(m_iShaderID, fragmentShader);
		glLinkProgram(m_iShaderID);
	}

	OpenGLShader::OpenGLShader(std::string filepath)
	{
		std::ifstream stream(filepath);
		std::string line;

		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;

		// Parsing Shader File
		while (std::getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos) {
					type = ShaderType::VERTEX;
				}
				else if (line.find("fragment") != std::string::npos) {
					type = ShaderType::FRAGMENT;
				}
			}
			else {
				ss[(int)type] << line << '\n';
			}
		}
		
		std::string _strVertexSource = ss[0].str();
		std::string _strFragmentSource = ss[1].str();

		const char* vertex = _strVertexSource.c_str();
		const char* fragment = _strFragmentSource.c_str();

		// Creating Vertex Shader
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertex, nullptr);
		glCompileShader(vertexShader);

		// Debugging Vertex Shader
		int vertResult;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertResult);
		if (vertResult == GL_FALSE)
		{
			int length;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)_malloca(length * sizeof(char));
			glGetShaderInfoLog(vertexShader, length, &length, message);

			std::cout << "Failed To Compile Vertex: " << std::endl;
			std::cout << message << std::endl;
		}

		// Creating Fragment Shader
		int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragment, nullptr);
		glCompileShader(fragmentShader);

		// Debugging Fragment Shader
		int fragResult;
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragResult);
		if (fragResult == GL_FALSE)
		{
			int length;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)_malloca(length * sizeof(char));
			glGetShaderInfoLog(fragmentShader, length, &length, message);

			std::cout << "Failed To Compile Fragment: " << std::endl;
			std::cout << message << std::endl;
		}

		// Creating Shader Program
		m_iShaderID = glCreateProgram();
		glAttachShader(m_iShaderID, vertexShader);
		glAttachShader(m_iShaderID, fragmentShader);
		glLinkProgram(m_iShaderID);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_iShaderID);
	}

	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}

	void* OpenGLShader::GetNative()
	{
		return (void*)m_iShaderID;
	}

	void OpenGLShader::SetInt(std::string uniformName, int uniformValue)
	{
		unsigned int uniformLocation = glGetUniformLocation(m_iShaderID, uniformName.c_str());
		glUniform1i(uniformLocation, uniformValue);
	}

	void OpenGLShader::SetMat4(std::string uniformName, glm::mat4 uniformValue)
	{
		unsigned int modelLoc = glGetUniformLocation(m_iShaderID, uniformName.c_str());
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(uniformValue));
	}
}
