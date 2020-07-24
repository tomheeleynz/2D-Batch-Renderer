#pragma once

#include <string>
#include "Arc/Renderer/Texture.h"

namespace Arc
{
	class OpenGLTexture : public Texture
	{
	public:
		OpenGLTexture(std::string path);
		
		virtual int GetWidth() override;
		virtual int GetHeight() override;
		virtual void* GetNative() override;
		virtual void Bind(uint32_t slot = 0) override;
	private:
		unsigned int m_iTextureID;
		int m_iWidth;
		int m_iHeight;
	};
}
