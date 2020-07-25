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
}

void EditorLayer::OnStart()
{
    Arc::SceneManager::GetCurrentScene()->Start();
}

void EditorLayer::OnUpdate()
{
    if (Arc::InputManager::GetKeyReleased(ARC_KEY_P))
    {
        Arc::SceneManager::ChangeScene("SecondScene");
    }
    
    if (Arc::InputManager::GetKeyReleased(ARC_KEY_D))
    {
        CreateScene("SecondScene");
    }
    
    Arc::SceneManager::GetCurrentScene()->Update();
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