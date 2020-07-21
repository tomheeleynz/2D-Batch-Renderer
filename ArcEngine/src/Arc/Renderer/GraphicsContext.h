#pragma once

namespace Arc
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
        virtual void* GetNative() = 0;
		static GraphicsContext* Create(void* window);

	private:

	};
}
