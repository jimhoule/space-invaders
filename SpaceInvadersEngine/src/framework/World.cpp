#include "framework/Core.h"
#include "framework/World.h"

namespace si
{
	World::World(Application* App)
		: m_App(App), m_HasBegunPlay(false)
	{}

	World::~World()
	{}

	void World::BeginPlayInternal()
	{
		if (m_HasBegunPlay)
		{
			return;
		}

		m_HasBegunPlay = true;
		BeginPlay();
	}

	void World::TickInternal(float DeltaTime)
	{
		Tick(DeltaTime);
	}

	void World::BeginPlay()
	{
		LOG("Begin play!!!");
	}

	void World::Tick(float DeltaTime) 
	{
		LOG("World is ticking at %f framerate", 1.f / DeltaTime);
	}
}