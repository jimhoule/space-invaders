#include "framework/Actor.h"
#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

#include <SFML/Graphics.hpp>

namespace si
{
	World::World(Application* OwningApp)
		: m_OwningApp(OwningApp), m_HasBegunPlay(false), m_Actors(), m_PendingActors()
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
		for (SharedPtr<Actor> PendingActor : m_PendingActors)
		{
			m_Actors.push_back(PendingActor);
			PendingActor->BeginPlayInternal();
		}

		m_PendingActors.clear();

		// NOTE: Because World is owner of Actor, it should tick first
		Tick(DeltaTime);

		for (List<SharedPtr<Actor>>::iterator iterator = m_Actors.begin(); iterator != m_Actors.end();)
		{
			// Destroys the actor if this one is waiting to be destroyed
			if (iterator->get()->IsDestructionPending())
			{
				iterator = m_Actors.erase(iterator);
				continue;
			}

			iterator->get()->TickInternal(DeltaTime);
			++iterator;
		}
	}

	void World::Render(sf::RenderWindow& Window)
	{
		for (SharedPtr<Actor> Actor : m_Actors)
		{
			Actor->Render(Window);
		}
	}

	sf::Vector2u World::GetWindowSize() const {
		return m_OwningApp->GetWindowSize();
	}

	void World::BeginPlay()
	{
		LOG("World begun play");
	}

	void World::Tick(float DeltaTime) 
	{
		LOG("World is ticking at %f framerate", 1.f / DeltaTime);
	}
}