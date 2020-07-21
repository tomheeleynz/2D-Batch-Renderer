#include "RenderAPI.h"

// Rendering API's
// ----- OpenGL
#include "Platform/Windows/OpenGL/OpenGLRenderAPI.h"
// ----- Metal
#include "Platform/MacOSX/Metal/MetalRenderAPI.h"

namespace Arc
{
#ifdef ARC_PLATFORM_WINDOWS
	RenderAPI::API RenderAPI::s_API = RenderAPI::API::OpenGL;
#endif

#ifdef ARC_PLATFORM_MACOSX
	RenderAPI::API RenderAPI::s_API = RenderAPI::API::Metal;
#endif

	RenderAPI* RenderAPI::Create()
	{
		switch (s_API)
		{
			case RenderAPI::API::None:
			{
				break;
			}
			case RenderAPI::API::OpenGL:
			{
			#ifdef ARC_PLATFORM_WINDOWS
				return static_cast<RenderAPI*>(new OpenGLRenderAPI());	
			#endif
				break;
			}
			case RenderAPI::API::Metal:
			{
			#ifdef ARC_PLATFORM_MACOSX
                return static_cast<RenderAPI*>(new MetalRenderAPI());
			#endif
				break;
			}
			case RenderAPI::API::Vulkan:
			{
				break;
			}
			default:
				break;
		}
	}
}
