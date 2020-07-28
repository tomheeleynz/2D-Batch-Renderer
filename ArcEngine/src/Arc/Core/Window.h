#pragma once
#include <memory>
#include <string>
#include <functional>

// Getting Context From Window
#include "Arc/Renderer/GraphicsContext.h"
namespace Arc
{
	struct WindowsProps
	{
		std::string _strTitle;
		int _iWidth;
		int _iHeight;

		WindowsProps(std::string title = "Arc Engine", int width = 1270, int height = 720) : _strTitle(title), _iWidth(width), _iHeight(height)
		{
		}
	};

	class Window
	{
	public:

		virtual ~Window() {};

		virtual void OnUpdate() = 0;
        
        virtual GraphicsContext* GetContext() = 0;
        virtual void UpdateTitle(std::string _strTitle) = 0;
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;

		static Window* Create(WindowsProps props = WindowsProps());
	private:

	};
}
