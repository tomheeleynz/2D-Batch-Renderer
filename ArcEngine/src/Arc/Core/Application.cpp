#include "Application.h"
#include <iostream>
#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/Texture.h"
#include "Arc/Scripting/ScriptingEngine.h"
#include <thread>

namespace Arc
{
    Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		m_bIsRunning = true;
		m_Window = std::unique_ptr<Window>(Window::Create());
        Renderer::Init(m_Window->GetContext());
        s_Instance = this;
	}

    Application* Application::Get()
    {
        return s_Instance;
    }

	Application::~Application()
	{

	}

	void Application::OnEvent()
	{
        
	}
	
	void Application::Run()
	{
    // Application Loop For MacOSX
    #ifdef ARC_PLATFORM_MACOSX
        auto currentLayer = m_LayerMap.find("Editor");
        currentLayer->second->OnStart();
        
        std::thread logicThread([](bool m_bIsRunning, Layer* currentLayer) {
            while (m_bIsRunning) {
                Renderer::Clear();
                Renderer::ClearColor(0.2f, 0.3f, 0.3f);
                currentLayer->OnUpdate();
            }
            
        }, m_bIsRunning, currentLayer->second);

        while (m_bIsRunning) {
            m_Window->OnUpdate();
        }
    #endif
        
    // Appliction Loop for Windows
    #ifdef ARC_PLATFORM_WINDOWS
		SceneManager::GetCurrentScene()->Start();

		while (m_bIsRunning)
        {
			SceneManager::GetCurrentScene()->Update();
			m_Window->OnUpdate();
		}
    #endif
	}

    void Application::AddLayer(Layer* _pLayer)
    {
        m_LayerMap.insert({_pLayer->GetName(), _pLayer});
    }

    void Application::OpenFile()
    {
        
    }
    
    Window* Application::GetWindow()
    {
        return m_Window.get();
    }
}
                                                                                                                         
