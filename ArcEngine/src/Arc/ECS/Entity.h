#pragma once

#include <entt/entt.hpp>
#include "Arc/Scenes/Scene.h"

namespace Arc
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity _EntityHandle, Scene* _pCurrentScene);

		template<typename T>
		bool HasComponent()
		{
			return m_ActiveScene->m_Registry.has<T>(m_EntityHandle);
		}

		template<typename T, typename ... Args>
		T& AddComponent(Args&&... args)
		{
			return m_ActiveScene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
		}

		template<typename T>
		T& GetComponent()
		{
			return m_ActiveScene->m_Registry.get<T>(m_EntityHandle);
		}

	private:
		entt::entity m_EntityHandle;
		Scene* m_ActiveScene;
	};
}