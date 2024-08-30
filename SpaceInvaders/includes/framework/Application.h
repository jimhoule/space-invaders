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
		sf::RenderWindow mWindow;
	};
}