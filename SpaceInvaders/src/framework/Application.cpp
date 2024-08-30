#include "framework/Application.h"

namespace si
{
	Application::Application()
		:mWindow{ sf::VideoMode(1024, 1440), "Space Invaders" }
	{}

	void Application::Run()
	{
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
		}
	}
}