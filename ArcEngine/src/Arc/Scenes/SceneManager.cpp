#include "SceneManager.h"

namespace Arc
{
	SceneManager* SceneManager::s_Instance = 0;

	SceneManager::SceneManager()
	{
		m_strCurrentSceneName = "SecondScene";
	
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

	void SceneManager::ChangeScene(std::string _strSceneName)
	{
		GetInstance()->ChangeSceneImpl(_strSceneName);
	}

	void SceneManager::AddSceneImpl(Scene* _pScene)
	{
		m_mapScenes.insert({_pScene->GetSceneName(), _pScene});
	}

	Scene* SceneManager::GetCurrentSceneImpl()
	{
		auto newScene = m_mapScenes.find(m_strCurrentSceneName);
		newScene->second->Start();
		return newScene->second;
	}

	void SceneManager::ChangeSceneImpl(std::string _strSceneName)
	{
		m_strCurrentSceneName = _strSceneName;
	}
}
