#include "gameFramework/GameApplication.h"

#include "config.h"
#include "spaceship/Spaceship.h"

#include <framework/Core.h>
#include <framework/World.h>

si::Application* GetApplication()
{
	return new si::GameApplication();
}

namespace si
{
	GameApplication::GameApplication()
		: Application(600, 980, "Space Invaders", sf::Style::Titlebar | sf::Style::Close)
	{
		WeakPtr<World> NewWorld = LoadWorld<World>();

		WeakPtr<Spaceship> NewSpaceship = NewWorld.lock()->SpawnActor<Spaceship>();
		NewSpaceship.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
		NewSpaceship.lock()->SetPosition(sf::Vector2f(300.f, 490.f));
		NewSpaceship.lock()->SetRotation(90.f);
		NewSpaceship.lock()->SetVelocity(sf::Vector2f(0.f, 200.f));
		//NewActor.lock()->Destroy();
	}
}