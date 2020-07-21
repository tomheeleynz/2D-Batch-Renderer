#pragma once

extern Arc::Application* Arc::CreateApplication();

int main()
{
	auto app = Arc::CreateApplication();
	app->Run();
	delete app;
}