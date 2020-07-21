#include "Buffer.h"
#include "Arc/Renderer/Renderer.h"

#include "Platform/MacOSX/Metal/MetalBuffer.h"
#include "Platform/Windows/OpenGL/OpenGLBuffer.h"

namespace Arc
    {
    
    //-------------------------------------
    //--------- Vertex Buffer--------------
    //-------------------------------------
    VertexBuffer* VertexBuffer::Create(Vertex* vertices, int size)
    {
        switch (Renderer::GetApi()) {
            case RenderAPI::API::OpenGL:
            {
#ifdef ARC_PLATFORM_WINDOWS
                return static_cast<VertexBuffer*>(new OpenGLVertexBuffer(vertices, size));
#endif
                break;
            }
            case RenderAPI::API::Metal:
            {
#ifdef ARC_PLATFORM_MACOSX
                return static_cast<VertexBuffer*>(new MetalVertexBuffer(vertices, size));
#endif
                break;
            }
            default:
                break;
        }
    }
    
    VertexBuffer* VertexBuffer::Create(int size)
    {
        switch (Renderer::GetApi())
        {
		case RenderAPI::API::OpenGL:
		{
#ifdef ARC_PLATFORM_WINDOWS
			return static_cast<VertexBuffer*>(new OpenGLVertexBuffer(size));
#endif
			break;
		}
            case RenderAPI::API::Metal:
            {
            #ifdef ARC_PLATFORM_MACOSX
                return static_cast<VertexBuffer*>(new MetalVertexBuffer(size));
            #endif
                break;
            }
            default:
                break;
        }
    }
    
    VertexBuffer::~VertexBuffer()
    {
        
    }
    
    //-------------------------------------
    //--------- Index Buffer---------------
    //-------------------------------------
    IndexBuffer* IndexBuffer::Create(uint32_t* indices, int size)
    {
        switch (Renderer::GetApi())
        {
            case RenderAPI::API::OpenGL:
            {
            #ifdef ARC_PLATFORM_WINDOWS
                return static_cast<IndexBuffer*>(new OpenGLIndexBuffer(indices, size));
            #endif
                break;
            }
            case RenderAPI::API::Metal:
            {
            #ifdef ARC_PLATFORM_MACOSX
                return static_cast<IndexBuffer*>(new MetalIndexBuffer(indices, size));
            #endif
                break;
            }
            default:
                break;
        }
    }
    }
