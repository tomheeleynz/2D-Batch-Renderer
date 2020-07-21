#include "GraphicsContext.h"
#include "Arc/Renderer/Renderer.h"

// Platform Contexts
#include "Platform/Windows/OpenGL/OpenGLGraphicsContext.h"
#include "Platform/MacOSX/Metal/MetalGraphicsContext.h"


namespace Arc
{
	GraphicsContext* GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetApi())
		{
			case RenderAPI::API::OpenGL:
			{
			#ifdef ARC_PLATFORM_WINDOWS
				return static_cast<GraphicsContext*>(new OpenGLGraphicsContext(static_cast<GLFWwindow*>(window)));
			#endif	
				break;
			}
			case RenderAPI::API::Metal:
			{
			#ifdef ARC_PLATFORM_MACOSX
				return static_cast<GraphicsContext*>(new MetalGraphicsContext(window));
			#endif
				break;
			}
			default:
				return nullptr;
				break;
		}
	}
}
