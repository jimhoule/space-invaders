#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
	si::Application* app = GetApplication();
	app->Run();

	delete app;
}