//
//  Editor.cpp
//  ArcEngine
//
//  Created by Thomas Heeley on 18/07/20.
//

#include <iostream>
#include <fstream>
#include "Editor.h"


EditorLayer::EditorLayer() : Arc::Layer("Editor")
{
    Arc::Scene* newScene = new Arc::Scene("src/Assets/FirstScene.arcsf");
    Arc::SceneManager::AddScene(newScene);
    m_ActiveScene = Arc::SceneManager::GetCurrentScene();
    entityPanel = new Arc::Panel();
}

void EditorLayer::OnStart()
{
    m_ActiveScene->Start();
}

void EditorLayer::OnUpdate()
{
    if (Arc::InputManager::GetKeyReleased(ARC_KEY_D))
    {
        Arc::Entity* testEntity = m_ActiveScene->AddEntity("Test");

        if (testEntity->HasComponent<Arc::Transform>()) {
            Arc::SpriteRenderer newSpriteRendererComponent;
            newSpriteRendererComponent.color = { 0.5f, 0.5f, 0.5f };
            testEntity->AddComponent<Arc::SpriteRenderer>(newSpriteRendererComponent);
        }
        else {
            std::cout << "Does Not Have Component" << std::endl;
        }
    }

    m_ActiveScene->Update();
}

void EditorLayer::CreateScene(std::string _strSceneName)
{
    std::string newSceneFileString = "src/Assets/" + _strSceneName + ".arcsf";

    std::ofstream newSceneFile(newSceneFileString);

    newSceneFile << '{' << std::endl;
    newSceneFile << "   \"name\": " << "\""<< _strSceneName << "\"," << std::endl;
    newSceneFile << "   \"Entities\": []" << std::endl;
    newSceneFile << "}" << std::endl;

    newSceneFile.close();
    
    Arc::Scene* newScene = new Arc::Scene(newSceneFileString);
    Arc::SceneManager::AddScene(newScene);
}