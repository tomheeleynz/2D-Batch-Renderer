#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Engine Includes
#include "Arc/Renderer/Shader.h"
#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/Buffer.h"
#include "Arc/Renderer/Texture.h"

namespace Arc
{
	class Renderer2D
	{
	public:
		static void Init();
		
		static void BeginScene();
		static void EndScene();
		static void Flush();

		static void DrawQuad(glm::vec3 position, glm::vec3 size, glm::vec3 color, float rotationAngle = 0);
        static void DrawQuad(glm::vec3 position, glm::vec3 size, glm::vec3 color, Texture* texture, float rotationAngl = 0);
		static void FlushAndReset();
	private:

	};
}
