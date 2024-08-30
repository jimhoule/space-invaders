#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"

int main()
{
	std::unique_ptr<si::Application> app = std::make_unique<si::Application>();
	//si::Application* app = new si::Application;
	app->Run();
}