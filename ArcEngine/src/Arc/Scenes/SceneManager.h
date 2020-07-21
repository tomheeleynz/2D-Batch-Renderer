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
	private:
		SceneManager();

		// Impl of Static Functions
		void AddSceneImpl(Scene* _pScene);
		Scene* GetCurrentSceneImpl();
	private:
		static SceneManager* s_Instance;
		Scene* m_pScene;
		std::map<std::string, Scene*> m_mapScenes;
	};
}

