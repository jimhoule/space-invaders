#pragma once

#include "spaceship/Spaceship.h"

namespace si {
	class PlayerSpaceship : public Spaceship
	{
	public:
		PlayerSpaceship(World* OwningWorld, const std::string& TexturePath = "SpaceShooterRedux/PNG/playerShip1_blue.png");
		virtual void Tick(float DeltaTime) override;
		void SetSpeed(float Speed);
		float GetSpeed() const { return m_Speed; };
	private:
		void HandleInput();
		void ConsumeInput(float DeltaTime);

		sf::Vector2f m_MovementDirection;
		float m_Speed;
	};
}