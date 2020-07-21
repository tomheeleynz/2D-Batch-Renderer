#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <thread>
#include <map>

// Engine Includes
#include "Arc/Renderer/Renderer.h"
#include "Arc/Scenes/SceneManager.h"
#include "Arc/Core/Window.h"
#include "Arc/Core/Layer.h"

namespace Arc
{
    class Application
    {
        public:
            Application();
            ~Application();

			void OnEvent();
            void Run();

			// Add Scenes
			void AddLayer(Layer* _pLayer);
            void OpenFile();
            
            // Getting Things From Application
            Window* GetWindow();
            
            static Application* Get();

        private:
            std::map<std::string, Layer*> m_LayerMap;
            std::unique_ptr<Window> m_Window;
			bool m_bIsRunning;
        private:
            static Application* s_Instance;
    };

	Application* CreateApplication();
}
