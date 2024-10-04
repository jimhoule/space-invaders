#include "framework/Application.h"

#include "framework/AssetsManager.h"
#include "framework/Core.h"
#include "framework/World.h"

#include <iostream>

namespace si
{
	Application::Application(unsigned int WindowWidth, unsigned int WindowHeight, const std::string& WindowTitle, sf::Uint32 WindowStyle)
		: m_Window(sf::VideoMode(WindowWidth, WindowHeight), WindowTitle, WindowStyle),
		m_TickClock(),
		m_CleanCycleClock(),
		m_CleanCycleInterval(2.f),
		m_TargetFrameRate(60.f),
		m_World(nullptr)
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

	sf::Vector2u Application::GetWindowSize() const
	{
		return m_Window.getSize();
	}

	void Application::TickInternal(float DeltaTime)
	{
		// NOTE: Because Application is owner of World, it should tick first
		Tick(DeltaTime);

		// Ticks world
		if (m_World != nullptr) {
			m_World->TickInternal(DeltaTime);
		}

		// Deletes unused assets
		if (m_CleanCycleClock.getElapsedTime().asSeconds() >= m_CleanCycleInterval)
		{
			m_CleanCycleClock.restart();
			AssetsManager::Get().CleanCycle();
		}
	}

	void Application::RenderInternal()
	{
		m_Window.clear();
		Render();
		m_Window.display();
	}

	void Application::Tick(float DeltaTime)
	{
		LOG("Application is ticking at %f framerate", 1.f / DeltaTime);
	}

	void Application::Render()
	{
		if (m_World == nullptr)
		{
			return;
		}

		m_World->Render(m_Window);
	}
}