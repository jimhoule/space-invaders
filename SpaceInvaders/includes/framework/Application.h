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
		void Tick(float DeltaTime);
		void Render();

		sf::RenderWindow m_Window;
		sf::Clock m_TickClock;
		float m_TargetFrameRate;
	};
}