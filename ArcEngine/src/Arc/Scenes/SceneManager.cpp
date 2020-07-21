#include "SceneManager.h"

namespace Arc
{
	SceneManager* SceneManager::s_Instance = 0;

	SceneManager::SceneManager()
	{
	
	
	}

	SceneManager* SceneManager::GetInstance()
	{
		if (!s_Instance)
		{
			s_Instance = new SceneManager();
			return s_Instance;
		}
		return s_Instance;
	}

	void SceneManager::AddScene(Scene* _pScene)
	{
		return GetInstance()->AddSceneImpl(_pScene);
	}

	Scene* SceneManager::GetCurrentScene()
	{
		return GetInstance()->GetCurrentSceneImpl();
	}

	void SceneManager::AddSceneImpl(Scene* _pScene)
	{
		std::pair<std::string, Scene*> sceneData = std::pair<std::string, Scene*>(_pScene->GetSceneName(), _pScene);
		m_mapScenes.insert(sceneData);
	}

	Scene* SceneManager::GetCurrentSceneImpl()
	{
		return m_mapScenes["First Scene"];
	}
}
