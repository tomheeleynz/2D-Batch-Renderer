//
//  Editor.cpp
//  ArcEngine
//
//  Created by Thomas Heeley on 18/07/20.
//

#include <iostream>
#include "Editor.h"


EditorLayer::EditorLayer() : Arc::Layer("Editor")
{
    Arc::Scene* newScene = new Arc::Scene("/Users/thomasheeley/Desktop/ArcEngine/Sandbox/src/Assets/FirstScene.json");
    Arc::SceneManager::AddScene(newScene);
}

void EditorLayer::OnStart()
{
    Arc::SceneManager::GetCurrentScene()->Start();
}

void EditorLayer::OnUpdate()
{
    if (Arc::InputManager::GetKeyPressed(ARC_KEY_P))
    {
        std::cout << "P Pressed" << std::endl;
    }
    
    if (Arc::InputManager::GetKeyReleased(ARC_KEY_D))
    {
        std::cout << "D Released" << std::endl;
    }
    
    Arc::SceneManager::GetCurrentScene()->Update();
}
