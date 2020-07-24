#include "OpenGLWindow.h"
#include "Arc/Core/InputManager.h"

namespace Arc
{
	Window* Window::Create(WindowsProps props)
	{
		return new OpenGLWindow(props);
	}

	OpenGLWindow::OpenGLWindow(WindowsProps props)
	{
		Init(props);
	}

	OpenGLWindow::~OpenGLWindow()
	{

	}

	void OpenGLWindow::Init(WindowsProps props)
	{
		m_Data.m_iHeight = props._iHeight;
		m_Data.m_iWidth = props._iWidth;
		m_Data.m_strTitle = props._strTitle.c_str();

		glfwInit();
		m_pWindow = glfwCreateWindow(m_Data.m_iWidth, m_Data.m_iHeight, m_Data.m_strTitle, nullptr, nullptr);
		
		m_Context = GraphicsContext::Create(m_pWindow);
		m_Context->Init();

		glfwSetWindowUserPointer(m_pWindow, &m_Data);
	
		// Window Key Down Key Press
		glfwSetKeyCallback(m_pWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			switch (action)
			{
			case GLFW_PRESS: {
				InputManager::SetKeyPressed(key);
				break;
			}
			case GLFW_RELEASE: {
				InputManager::SetKeyReleased(key);
				break;
			}
			default:
				break;
			}
		});

		// Window Close Callback
		glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* window) {
			 WindowData* windowData = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		});

		// Window Resize Callback
		glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		});
	}

	void OpenGLWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_pWindow);
	}


	void OpenGLWindow::Shutdown()
	{

	}

	void OpenGLWindow::UpdateTitle(std::string _strTitle)
	{
	
	}

	GraphicsContext* OpenGLWindow::GetContext()
	{
		return m_Context;
	}
}
