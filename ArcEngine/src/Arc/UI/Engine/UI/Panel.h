#pragma once
#include "Arc/UI/Engine/Base/UIComponent.h"

namespace Arc
{
	class Panel : public UIComponent
	{
	public:
		Panel();

		void Start();
		void Update(float mouseXCoord, float yMouseCoord, bool mousePressed);

	private:
		float m_iWidth;
		float m_iHeight;
		glm::vec3 m_vecColor;
	};
}

