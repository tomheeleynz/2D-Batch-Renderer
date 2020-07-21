#pragma once
#include "Arc/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Arc
{
	class OpenGLGraphicsContext : public GraphicsContext
	{
	public:
		OpenGLGraphicsContext(GLFWwindow* window);
		void Init() override;
		void* GetNative() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}