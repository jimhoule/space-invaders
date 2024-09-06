#include "gameFramework/GameApplication.h"

#include "config.h"

#include <framework/Actor.h>
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
		WeakPtr<Actor> NewActor = NewWorld.lock()->SpawnActor<Actor>();
		NewActor.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
		//NewActor.lock()->Destroy();
	}
}