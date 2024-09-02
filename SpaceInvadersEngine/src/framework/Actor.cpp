#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace si
{
	Actor::Actor(World* OwningWorld)
		: m_OwningWorld(OwningWorld), m_HasBegunPlay(false)
	{}

	Actor::~Actor()
	{
		LOG("Actor destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (m_HasBegunPlay)
		{
			return;
		}

		m_HasBegunPlay = true;
		BeginPlay();
	}

	void Actor::BeginPlay()
	{
		LOG("Actor begun play");
	}

	void Actor::Tick(float DeltaTime)
	{
		LOG("Actor ticking at %f framerate", 1.f / DeltaTime);
	}
}