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
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}

	void Application::TickInternal(float DeltaTime)
	{
		Tick(DeltaTime);
	}

	void Application::RenderInternal()
	{
		m_Window.clear();
		Render();
		m_Window.display();
	}

	void Application::Tick(float DeltaTime)
	{
		std::cout << "Ticking at " << 1.f / DeltaTime << " framerate" << std::endl;
	}

	void Application::Render()
	{
		sf::RectangleShape rect{ sf::Vector2f{100, 100} };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(50, 50);
		rect.setPosition(m_Window.getSize().x / 2.f, m_Window.getSize().y / 2.f);

		m_Window.draw(rect);
	}
}