#pragma once

#include <SFML/Graphics.hpp>

namespace si
{
	class Application
	{
	public:
		Application();
		void Run();

	private:
		void TickInternal(float DeltaTime);
		void RenderInternal();
		virtual void Tick(float DeltaTime);
		virtual void Render();

		sf::RenderWindow m_Window;
		sf::Clock m_TickClock;
		float m_TargetFrameRate;
	};
}