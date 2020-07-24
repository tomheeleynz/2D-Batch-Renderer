#include "Platform/Windows/OpenGL/OpenGLTexture.h"
#include <iostream>
#include <SOIL/SOIL.h>
#include <glad/glad.h>

namespace Arc
{
	OpenGLTexture::OpenGLTexture(std::string path)
	{
		int width, height;
		unsigned char* image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);

		if (!image)
		{
			std::cout << "Failed To Load Texture" << std::endl;
			std::cout << SOIL_last_result() << std::endl;
		}
		else {
			glGenTextures(1, &m_iTextureID);
			glBindTexture(GL_TEXTURE_2D, m_iTextureID);
			
			m_iHeight = height;
			m_iWidth = width;
			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
		}

	}

	int OpenGLTexture::GetWidth()
	{
		return m_iWidth;
	}

	int OpenGLTexture::GetHeight()
	{
		return m_iHeight;
	}

	void* OpenGLTexture::GetNative()
	{
		return (void*)m_iTextureID;
	}

	void OpenGLTexture::Bind(uint32_t slot)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_iTextureID);
	}
}