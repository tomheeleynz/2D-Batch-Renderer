#pragma once
#include <glm/glm.hpp>

namespace Arc
{
	class UIComponent
	{
	public:
		UIComponent();

		glm::vec3 GetPos();
		void SetPos(glm::vec3 pos);
	private:
		glm::vec3 m_Position;
	};
}