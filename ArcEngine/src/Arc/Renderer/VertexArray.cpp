#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/Renderer.h"

#include "Platform/Windows/OpenGL/OpenGLVertexArray.h"
#include "Platform/MacOSX/Metal/MetalVertexArray.h"

namespace Arc
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetApi())
		{
		case RenderAPI::API::OpenGL:
		{
		#ifdef ARC_PLATFORM_WINDOWS
			return static_cast<VertexArray*>(new OpenGLVertexArray());
		#endif
			break;
		}
        case RenderAPI::API::Metal:
        {
        #ifdef ARC_PLATFORM_MACOSX
            return static_cast<VertexArray*>(new MetalVertexArray());
        #endif
            break;
        }
		default:
			break;
		}
        
        return nullptr;
	}
}


