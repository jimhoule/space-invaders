#include "gameFramework/GameApplication.h"

#include <framework/World.h>

si::Application* GetApplication()
{
	return new si::GameApplication();
}

namespace si
{
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}