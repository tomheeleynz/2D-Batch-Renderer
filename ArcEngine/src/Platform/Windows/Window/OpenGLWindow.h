#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <vector>
#include <iostream>
#include "Arc/Core/Window.h"
#include "Arc/Renderer/GraphicsContext.h"

namespace Arc
{
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(WindowsProps props);
		~OpenGLWindow();

		void OnUpdate() override;
		GraphicsContext* GetContext() override;

	private:
		void Init(WindowsProps props);
		void Shutdown();

	private:
		GLFWwindow* m_pWindow;

		struct WindowData
		{
			int m_iWidth;
			int m_iHeight;
			const char* m_strTitle;
		
			std::function<void()> EventCallback;
		};

		WindowData m_Data;
		GraphicsContext* m_Context;
	};
}