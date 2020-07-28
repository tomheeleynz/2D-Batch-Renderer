//
//  Renderer2D.cpp
//  ArcEngine
//
//  Created by Thomas Heeley on 1/07/20.
//

#include "Arc/Renderer/Renderer2D.h"
#include "Arc/Renderer/RenderCommand.h"
#include "Arc/Renderer/Texture.h"

namespace Arc {
    struct Rendere2DData
    {
		IndexBuffer* quadIB;
        Shader* basic2DShader;
        //Texture* basicTexture;
        
        // Rendering Amount Variables
		// ---- Quad
		int maxQuads = 100;
		int maxQuadVertices = maxQuads * 4;
		int quadCount = 0;
		int quadIndiceCount = 0;
		Vertex* quadVertices;
		VertexArray* quadVA;
		VertexBuffer* quadBuffer;
		glm::vec4 quadBase[4];
		uint32_t* indices;
    };

    static Rendere2DData s_Data;

    void Renderer2D::Init()
    {
        s_Data.basic2DShader = Shader::Create("src/Assets/Basic.shader");
        //s_Data.basicTexture = Texture::Create("/Users/thomasheeley/Downloads/Adventurer/Individual Sprites/adventurer-attack1-00.png");
        
		// Quad Base
		s_Data.quadBase[0] = {0.5f, 0.5f, 0.0f, 1.0f};
		s_Data.quadBase[1] = {0.5f, -0.5f, 0.0f, 1.0f};
		s_Data.quadBase[2] = {-0.5f, -0.5f, 0.0f, 1.0f};
		s_Data.quadBase[3] = {-0.5f, 0.5f, 0.0f, 1.0f};

		s_Data.indices = new uint32_t[s_Data.maxQuads * 6];

		int offset = 0;
        
		for (int i = 0; i < s_Data.maxQuads * 6; i+=6)
		{
			s_Data.indices[i] = (offset * 4) + 0;
			s_Data.indices[i + 1] = (offset * 4) + 1;
			s_Data.indices[i + 2] = (offset * 4) + 3;
			s_Data.indices[i + 3] = (offset * 4) + 1;
			s_Data.indices[i + 4] = (offset * 4) + 2;
			s_Data.indices[i + 5] = (offset * 4) + 3;
			offset++;
		}

		s_Data.quadVertices = new Vertex[s_Data.maxQuadVertices];
		s_Data.quadVA = VertexArray::Create();
		s_Data.quadIB = IndexBuffer::Create(s_Data.indices, s_Data.maxQuads * 6);
		s_Data.quadBuffer = VertexBuffer::Create(s_Data.maxQuadVertices * sizeof(Vertex));
    }
    
    void Renderer2D::BeginScene()
    {
        s_Data.basic2DShader->Bind();
		s_Data.quadVA->AddVertexBuffer(s_Data.quadBuffer);
		s_Data.quadVA->SetIndexBuffer(s_Data.quadIB);
		s_Data.quadVA->AddShader(s_Data.basic2DShader);
    }

    void Renderer2D::EndScene()
    {
		s_Data.quadBuffer->SetData(s_Data.quadVertices, s_Data.quadCount * 4 * sizeof(Vertex));
		Flush();
    }

    void Renderer2D::Flush()
    {
        s_Data.quadVA->Bind();
		RenderCommand::DrawIndexedPrimative(s_Data.quadVA, s_Data.maxQuads * 6);
        s_Data.quadCount = 0;
    }

    void Renderer2D::DrawQuad(glm::vec3 position, glm::vec3 size, glm::vec3 color, float rotationAngle)
	{
		int quadSize = 4;

		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
		glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), size);
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationAngle), {0.0f, 0.0f, 1.0f});
		
        glm::vec2 textureCoords[4] = {
            {1.0f, 1.0f},
            {1.0f, 0.0f},
            {0.0f, 0.0f},
            {0.0f, 1.0f}
        };
        
		for (int i = 0; i < quadSize; i++)
		{
			Vertex v;
			v.position = translationMatrix * rotationMatrix * scaleMatrix * s_Data.quadBase[i];
			v.color = color;
            v.texture = textureCoords[i];
			s_Data.quadVertices[(s_Data.quadCount * 4) + i] = v;
		}

		s_Data.quadCount++;
	}

    void Renderer2D::DrawQuad(glm::vec3 position, glm::vec3 size, glm::vec3 color, Texture *texture, float rotationAngle)
    {
        int quadSize = 4;

        glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), size);
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationAngle), {0.0f, 0.0f, 1.0f});
        
        glm::vec2 textureCoords[4] = {
            {1.0f, 1.0f},
            {1.0f, 0.0f},
            {0.0f, 0.0f},
            {0.0f, 1.0f}
        };
        
        for (int i = 0; i < quadSize; i++)
        {
            Vertex v;
            v.position = translationMatrix * rotationMatrix * scaleMatrix * s_Data.quadBase[i];
            v.color = color;
            v.texture = textureCoords[i];
            s_Data.quadVertices[(s_Data.quadCount * 4) + i] = v;
        }

        s_Data.quadCount++;
    }

    void Renderer2D::FlushAndReset()
    {
        delete s_Data.quadVertices;
        s_Data.quadVertices = new Vertex[s_Data.maxQuadVertices];
        s_Data.quadCount = 0;
    }

}
