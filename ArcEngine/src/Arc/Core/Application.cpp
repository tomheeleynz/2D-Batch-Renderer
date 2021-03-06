#include <iostream>
#include <filesystem>
#include "Application.h"
#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/Texture.h"
#include "Arc/Scripting/ScriptingEngine.h"

namespace Arc
{
    Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		m_bIsRunning = true;
		m_Window = std::unique_ptr<Window>(Window::Create());
        Renderer::Init(m_Window->GetContext());
        ScriptingEngine::Init("..\\bin\\exe\\Debug\\ExampleApp.dll");
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
        auto currentLayer = m_LayerMap.find("Editor");
        currentLayer->second->OnStart();
        
        while (m_bIsRunning) {
            Renderer::Clear();
            Renderer::ClearColor(0.2f, 0.3f, 0.3f);
            currentLayer->second->OnUpdate();
            m_Window->OnUpdate();
        }
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
                                                                                                                         
