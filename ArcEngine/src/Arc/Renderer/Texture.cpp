#include "Arc/Renderer/Texture.h"
#include "Arc/Renderer/Renderer.h"

#include "Platform/Windows/OpenGL/OpenGLTexture.h"
#include "Platform/MacOSX/Metal/MetalTexture.h"

namespace Arc
{
	Texture* Texture::Create(std::string _strFileName)
	{
		switch (Renderer::GetApi())
		{
		case RenderAPI::API::OpenGL:
		{
		#ifdef ARC_PLATFORM_WINDOWS
			return static_cast<Texture*>(new OpenGLTexture(_strFileName));
		#endif
			break;
		}
        case RenderAPI::API::Metal:
        {
        #ifdef ARC_PLATFORM_MACOSX
            return static_cast<Texture*>(new MetalTexture(_strFileName));
        #endif
            break;
        }
		default:
			break;
		}
	}
}
