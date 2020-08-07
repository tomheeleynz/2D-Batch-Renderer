#include "Entity.h"

namespace Arc
{
	Entity::Entity(entt::entity _EntityHandle, Scene* _pCurrentScene)
	{
		m_EntityHandle = _EntityHandle;
		m_ActiveScene = _pCurrentScene;
	}


}