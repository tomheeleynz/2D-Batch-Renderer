#include "Panel.h"
#include <iostream>
#include "Arc/Renderer/Renderer2D.h"

namespace Arc
{
	Panel::Panel()
	{
		m_iHeight = 0.5f;
		m_iWidth = 0.4f;
		m_vecColor = {1.0f, 0.0f, 0.0f};
		SetPos({0.7f, 0.0f, 0.0f});
	}

	void Panel::Start()
	{
				
	}

	void Panel::Update(float mouseXCoord, float mouseYCoord, bool mousePressed)
	{
		glm::vec3 currentPos = GetPos();

		float minX = currentPos.x - m_iWidth / 2;
		float maxX = currentPos.x + m_iWidth / 2;
		float minY = currentPos.y - m_iHeight /2;
		float maxY = currentPos.y + m_iHeight / 2;

		if (mousePressed)
		{
			if (mouseXCoord > minX && mouseYCoord > minY && mouseXCoord < maxX && mouseYCoord < maxY)
			{
				SetPos({ mouseXCoord, mouseYCoord, 0.0f });
			}
		}
	
		Renderer2D::DrawQuad(GetPos(), {m_iWidth, m_iHeight, 0.0f}, m_vecColor, 0.0f);
	}
}
