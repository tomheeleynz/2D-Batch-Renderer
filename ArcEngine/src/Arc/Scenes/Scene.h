#pragma once
#include <string>
#include <map>
#include <entt/entt.hpp>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

namespace Arc
{
	class Entity;

	class Scene
	{
	public:
		Scene(std::string _strSceneFilePath);

		void Start();
        void Update();
        Entity* AddEntity(std::string _strEntityName);
        
		std::string GetSceneName();
	private:
        rapidjson::Document m_SceneDocument;
		std::string m_strSceneName;
        std::map<std::string, Entity*> m_EntityMap;
        entt::registry m_Registry;

		friend class Entity;
	};
}
