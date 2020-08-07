// External Includes
#include <iostream>
#include <fstream>

// Engine Includes
#include "Scene.h"
#include "Arc/ECS/Entity.h"
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

                        /// Start Method
                        MonoMethod* startMethod = ScriptingEngine::CreateMethod("Start", scriptClass);
                        // Update Method
                        MonoMethod* updateMethod = ScriptingEngine::CreateMethod("Update", scriptClass);

                        m_Registry.emplace<Script>(entity, scriptName, scriptClass, scriptObject, startMethod, updateMethod);
                       
                        break;
                    }
                    default:
                        break;
                }
            }
            
            m_EntityMap.insert({entityName, new Entity(entity, this)});
        }
	}
    
    void Scene::Start()
    {
        Renderer2D::FlushAndReset();

        {
            auto view = m_Registry.view<Script>();

            for (auto entity : view)
            {
                auto& script = view.get<Script>(entity);
                ScriptingEngine::RunScript(script.startMethod, script.scriptObject);
            }
        }
    }
    
    void Scene::Update()
    {

        {
            auto view = m_Registry.view<Script>();

            for (auto entity : view)
            {
                auto& script = view.get<Script>(entity);
                ScriptingEngine::RunScript(script.updateMethod, script.scriptObject);
            }
        }

        {

            auto view = m_Registry.view<Transform, SpriteRenderer>();

            Renderer2D::BeginScene();

            for (auto entity : view)
            {
                auto& transform = view.get<Transform>(entity);
                auto& spriteRenderer = view.get<SpriteRenderer>(entity);
                Renderer2D::DrawQuad(transform.position, transform.scale, spriteRenderer.color, transform.rotationAngle);
            }

            Renderer2D::EndScene();
        }
    }
    
    Entity* Scene::AddEntity(std::string _strEntityName)
    {
        auto entityHandle = m_Registry.create();
        Entity* newEntity = new Entity(entityHandle, this);
        
        Transform newTransformComponent;
        newTransformComponent.position = {0.0f, 0.7f, 0.0f};
        newTransformComponent.rotation = { 0.0f, 0.0f, 1.0f };
        newTransformComponent.scale = {0.5f, 0.5f, 1.0f};
        newTransformComponent.rotationAngle = 0.0f;

        newEntity->AddComponent<Transform>(newTransformComponent);
        m_EntityMap.insert({_strEntityName, newEntity});
        return newEntity;
    }

	std::string Scene::GetSceneName()
	{
		return m_strSceneName;
	}
}
