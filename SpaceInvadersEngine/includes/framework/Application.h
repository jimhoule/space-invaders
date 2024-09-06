#pragma once

#include "framework/Core.h"

#include <SFML/Graphics.hpp>
#include <string>

namespace si
{
	class World;

	class Application
	{
	public:
		Application(unsigned int WindowWidth, unsigned int WindowHeight, const std::string& WindowTitle, sf::Uint32 WindowStyle);
		void Run();

		template<typename TWorld>
		WeakPtr<TWorld> LoadWorld();

	private:
		void TickInternal(float DeltaTime);
		void RenderInternal();
		virtual void Tick(float DeltaTime);
		virtual void Render();

		sf::RenderWindow m_Window;
		sf::Clock m_TickClock;
		float m_TargetFrameRate;
		SharedPtr<World> m_World;
	};

	// Template implementations
	// NOTE: Templates cannot be implemented in a cpp file
	template<typename TWorld>
	WeakPtr<TWorld> Application::LoadWorld()
	{
		SharedPtr<TWorld> World{ new TWorld{this} };
		m_World = World;
		m_World->BeginPlayInternal();

		return World;
	}
}