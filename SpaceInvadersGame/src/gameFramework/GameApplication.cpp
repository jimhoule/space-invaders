#include "gameFramework/GameApplication.h"

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
	{
		WeakPtr<World> NewWorld = LoadWorld<World>();
		WeakPtr<Actor> NewActor = NewWorld.lock()->SpawnActor<Actor>();
		NewActor.lock()->Destroy();
	}
}