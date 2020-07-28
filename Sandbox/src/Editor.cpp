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
    entityPanel = new Arc::Panel();
}

void EditorLayer::OnStart()
{
    Arc::SceneManager::GetCurrentScene()->Start();
    entityPanel->Start();
}

void EditorLayer::OnUpdate()
{
    bool leftClickPressed = Arc::InputManager::GetMouseKeyPressed(ARC_MOUSE_BUTTON_LEFT);
    bool leftClickReleased = Arc::InputManager::GetMouseKeyReleased(ARC_MOUSE_BUTTON_LEFT);

    // Things Needed for Editor Update Loop
    int currentWindowHeight = Arc::Application::Get()->GetWindow()->GetHeight();
    int currentWindowWidth = Arc::Application::Get()->GetWindow()->GetWidth();
    auto [x, y] = Arc::InputManager::GetMouseCoords();

    // Converting Mouse Coords
    x = (x - (currentWindowWidth / 2)) / (currentWindowWidth / 2);
    y = (-1 * (y - (currentWindowHeight / 2))) / (currentWindowHeight / 2);

    Arc::Renderer2D::BeginScene();
   
    // Updating Scene Entities
    Arc::SceneManager::GetCurrentScene()->Update();

    Arc::Renderer2D::EndScene();
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