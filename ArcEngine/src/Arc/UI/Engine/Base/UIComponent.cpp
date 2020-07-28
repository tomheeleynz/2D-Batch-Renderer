#include "UIComponent.h"

namespace Arc
{
	UIComponent::UIComponent()
	{
		m_Position = { 0.0f, 0.0f, 0.0f };
	}

	void UIComponent::SetPos(glm::vec3 pos)
	{
		m_Position = pos;
	}

	glm::vec3 UIComponent::GetPos()
	{
		return m_Position;
	}
}