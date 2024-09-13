#include "spaceship/Spaceship.h"

namespace si
{
	Spaceship::Spaceship(World* OwningWorld, const std::string& TexturePath)
		: Actor(OwningWorld, TexturePath), m_Velocity()
	{}

	void Spaceship::SetVelocity(const sf::Vector2f& Velocity)
	{
		m_Velocity = Velocity;
	}

	void Spaceship::Tick(float DeltaTime)
	{
		Actor::Tick(DeltaTime);

		AddPositionOffset(m_Velocity * DeltaTime);
	}
}