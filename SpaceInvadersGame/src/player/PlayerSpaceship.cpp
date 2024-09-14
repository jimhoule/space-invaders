#include "player/PlayerSpaceship.h"

#include <SFML/System.hpp>

namespace si
{
	PlayerSpaceship::PlayerSpaceship(World* OwningWorld, const std::string& TexturePath)
		: Spaceship(OwningWorld, TexturePath), m_MovementDirection(), m_Speed(200.f)
	{}

	void PlayerSpaceship::Tick(float DeltaTime)
	{
		Spaceship::Tick(DeltaTime);

		HandleInput();
		ConsumeInput(DeltaTime);
	}

	void PlayerSpaceship::SetSpeed(float Speed)
	{
		m_Speed = Speed;
	}

	void PlayerSpaceship::HandleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_MovementDirection.y = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_MovementDirection.y = 1.f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_MovementDirection.x = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_MovementDirection.x = 1.f;
		}
	}

	void PlayerSpaceship::ConsumeInput(float DeltaTime)
	{
		SetVelocity(m_MovementDirection * m_Speed);

		m_MovementDirection.x = 0.f;
		m_MovementDirection.y = 0.f;
	}
}