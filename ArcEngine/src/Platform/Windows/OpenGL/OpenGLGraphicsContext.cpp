#include "Platform/Windows/OpenGL/OpenGLGraphicsContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Arc
{
	OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow* window) : m_WindowHandle(window)
	{

	}

	void OpenGLGraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}
	void* OpenGLGraphicsContext::GetNative()
	{
		return nullptr;
	}
}