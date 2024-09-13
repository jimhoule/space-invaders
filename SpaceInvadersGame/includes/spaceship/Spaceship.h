#pragma once

#include <framework/Actor.h>

namespace si
{
	class Spaceship : public Actor
	{
	public:
		Spaceship(World* OwningWorld, const std::string& TexturePath = "");

		void SetVelocity(const sf::Vector2f& Velocity);
		sf::Vector2f GetVelocity() const { return m_Velocity; };
		virtual void Tick(float DeltaTime) override;

	private:
		sf::Vector2f m_Velocity;
	};
}