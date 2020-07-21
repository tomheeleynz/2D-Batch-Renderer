#pragma once

#include <string>

namespace Arc
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;

		virtual void Bind(uint32_t slot = 0) = 0;
        virtual void* GetNative() = 0;

		static Texture* Create(std::string _strFilePath);
	private:

	};
}
