#include <iostream>

#include "framework/Application.h"

namespace si
{
	Application::Application()
		:m_Window{ sf::VideoMode(1024, 1440), "Space Invaders" },
		m_TickClock{},
		m_TargetFrameRate{ 60.f }
	{}

	void Application::Run()
	{
		m_TickClock.restart();

		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / m_TargetFrameRate;

		while (m_Window.isOpen())
		{
			sf::Event windowEvent;
			while (m_Window.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					m_Window.close();
				}
			}

			// Gets the ellapsed time
			accumulatedTime += m_TickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				Tick(targetDeltaTime);
				Render();
			}
		}
	}

	void Application::Tick(float DeltaTime)
	{
		std::cout << "Ticking at " << 1.f / DeltaTime << " framerate" << std::endl;
	}

	void Application::Render()
	{

	}
}