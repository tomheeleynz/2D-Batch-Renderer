// External Includes
#include <iostream>
#include <fstream>

// Engine Includes
#include "Scene.h"
#include "Arc/ECS/Components.h"
#include "Arc/Renderer/Renderer2D.h"
#include "Arc/Scripting/ScriptingEngine.h"


namespace Arc
{
	Scene::Scene(std::string _strSceneFilePath)
	{
        std::ifstream sceneFile(_strSceneFilePath);
        rapidjson::IStreamWrapper isw(sceneFile);
        m_SceneDocument.ParseStream(isw);
    
        // Setting Scene Name
        m_strSceneName = m_SceneDocument["name"].GetString();
        
        // Getting Entities Array
        rapidjson::Value& entities = m_SceneDocument["Entities"];
        
        for (int i = 0; i < entities.Size(); i++)
        {
            std::string entityName = entities[i]["name"].GetString();
            rapidjson::Value& components = entities[i]["components"];
            auto entity = m_Registry.create();
            
            std::cout << entityName << std::endl;
            
            for (int j = 0; j < components.Size(); j++)
            {
                int componentID = components[j]["id"].GetInt();
                std::string componentName = components[j]["name"].GetString();
                std::cout << " - " << componentName << std::endl;
                
                switch (componentID) {
                    case 0:
                    {
                        glm::vec3 position = {components[j]["position"][0].GetFloat(), components[j]["position"][1].GetFloat(), components[j]["position"][2].GetFloat() };
                        glm::vec3 scale = {components[j]["scale"][0].GetFloat(), components[j]["scale"][1].GetFloat(), components[j]["scale"][2].GetFloat() };
                        glm::vec3 rotation = {components[j]["rotation"][0].GetFloat(), components[j]["rotation"][1].GetFloat(), components[j]["rotation"][2].GetFloat() };
                        float angle = components[j]["angle"].GetFloat();
                        m_Registry.emplace<Transform>(entity, position, scale, rotation, angle);
                        break;
                    }
                    case 1:
                    {
                        glm::vec3 color = {components[j]["color"][0].GetFloat(), components[j]["color"][1].GetFloat(), components[j]["color"][2].GetFloat() };
                        std::string textureFile = components[j]["textureFile"].GetString();
                        m_Registry.emplace<SpriteRenderer>(entity, color, textureFile);
                        break;
                    }
                    case 2:
                    {
                        std::string scriptName = components[j]["scriptName"].GetString();
                        MonoClass* scriptClass = ScriptingEngine::CreateClass(scriptName);
                        MonoObject* scriptObject = ScriptingEngine::CreateObject(scriptClass);

                        // Start Method
                        MonoMethod* startMethod = ScriptingEngine::CreateMethod("Start", scriptClass);
                        MonoMethod* updateMethod = ScriptingEngine::CreateMethod("Update", scriptClass);

                        Script newScriptComponent;
                        newScriptComponent._scriptName = scriptName;
                        newScriptComponent.scriptClass = scriptClass;
                        newScriptComponent.scriptObject = scriptObject;
                        newScriptComponent.startMethod = startMethod;
                        newScriptComponent.updateMethod = updateMethod;

                        m_Registry.emplace<Script>(entity, newScriptComponent);

                        break;
                    }
                    default:
                        break;
                }
            }
            
            m_EntityMap.insert({entityName, entity});
        }
	}
    
    void Scene::Start()
    {
        Renderer2D::FlushAndReset();

        auto startScriptView = m_Registry.view<Script>();

        for (auto entity : startScriptView)
        {
            auto& scriptComponent = startScriptView.get<Script>(entity);
            ScriptingEngine::RunScript(scriptComponent.startMethod, scriptComponent.scriptObject);
        }
    }
    
    void Scene::Update()
    {
        auto renderingView = m_Registry.view<Transform, SpriteRenderer>();

        // Update Rendering Components
        Renderer2D::BeginScene();
        
        for (auto entity : renderingView)
        {
            auto& transform = renderingView.get<Transform>(entity);
            auto& spriteRenderer = renderingView.get<SpriteRenderer>(entity);
            
            Renderer2D::DrawQuad(transform.position, transform.scale, spriteRenderer.color, transform.rotationAngle);
        }
        
        Renderer2D::EndScene();
    }
    
    void Scene::AddEntity(std::string _strEntityName)
    {
        auto entity = m_Registry.create();
        m_Registry.emplace<Transform>(entity);
        m_Registry.emplace<SpriteRenderer>(entity);
        m_EntityMap.insert({_strEntityName, entity});
    }

	std::string Scene::GetSceneName()
	{
		return m_strSceneName;
	}
}
