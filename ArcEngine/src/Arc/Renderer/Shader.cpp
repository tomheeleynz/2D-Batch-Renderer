#include "Shader.h"

// Platform Specific Shaders
#include "Arc/Renderer/Renderer.h"
#include "Platform/Windows/OpenGL/OpenGLShader.h"
#include "Platform/MacOSX/Metal/MetalShader.h"

namespace Arc
{
	Shader* Shader::Create(const char* vertexSrc, const char* fragmentSrc)
	{
		return nullptr;
	}

	Shader* Shader::Create(std::string filepath)
	{
        switch (Renderer::GetApi()) {
			case RenderAPI::API::OpenGL:
			{
			#ifdef ARC_PLATFORM_WINDOWS
				return new OpenGLShader(filepath);
			#endif
				break;
			}
            case RenderAPI::API::Metal:
            {
			#ifdef ARC_PLATFORM_MACOSX
                return new MetalShader(filepath);
			#endif
				break;
            }
            default:
                break;
        }
	}
}
