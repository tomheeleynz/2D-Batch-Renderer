#include <Arc.h>
#include <Arc/Core/EntryPoint.h>

#include "Editor.h"

class Sandbox : public Arc::Application
{
public:
	Sandbox()
	{
        AddLayer(new EditorLayer());
	}

	~Sandbox()
	{
	
	}
private:

};

Arc::Application* Arc::CreateApplication()
{
	return new Sandbox();
}

