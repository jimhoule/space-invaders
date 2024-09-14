#include "gameFramework/GameApplication.h"

#include "config.h"
#include "player/PlayerSpaceship.h"
#include "spaceship/Spaceship.h"

#include <framework/AssetsManager.h>
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
		AssetsManager::Get().SetAssetsRootDirectory(GetResourceDir());

		WeakPtr<World> NewWorld = LoadWorld<World>();

		WeakPtr<PlayerSpaceship> NewPlayerSpaceship = NewWorld.lock()->SpawnActor<PlayerSpaceship>();
		//NewPlayerSpaceship.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
		NewPlayerSpaceship.lock()->SetPosition(sf::Vector2f(300.f, 490.f));
		//NewPlayerSpaceship.lock()->SetRotation(90.f);
		//NewPlayerSpaceship.lock()->SetVelocity(sf::Vector2f(0.f, 200.f));
		//NewActor.lock()->Destroy();
	}
}