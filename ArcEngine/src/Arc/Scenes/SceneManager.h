#pragma once
#include "Scene.h"
#include <string>
#include <map> 

namespace Arc
{
	class SceneManager
	{
	public:
		static SceneManager* GetInstance();

		static void AddScene(Scene* _pScene);
		static Scene* GetCurrentScene();
		static void ChangeScene(std::string _strSceneName);
	private:
		SceneManager();

		// Impl of Static Functions
		void AddSceneImpl(Scene* _pScene);
		Scene* GetCurrentSceneImpl();
		void ChangeSceneImpl(std::string _strSceneName);
	private:
		static SceneManager* s_Instance;
		std::string m_strCurrentSceneName;
		std::map<std::string, Scene*> m_mapScenes;
	};
}

