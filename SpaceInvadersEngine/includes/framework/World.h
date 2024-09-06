#pragma once

#include "framework/Core.h"

namespace si
{
	class Actor;
	class Application;

	class World
	{
	public:
		World(Application* OwningApp);
		virtual ~World();

		void BeginPlayInternal();
		void TickInternal(float DeltaTime);
		void Render(sf::RenderWindow& Window);

		template<typename TActor>
		WeakPtr<TActor> SpawnActor();
	private:
		Application* m_OwningApp;
		bool m_HasBegunPlay;
		List<SharedPtr<Actor>> m_Actors;
		// NOTE: We use a pending actors list to make sure we don't add any actor in the middle of an actors list update
		List<SharedPtr<Actor>> m_PendingActors;

		void BeginPlay();
		void Tick(float DeltaTime);
	};

	// Template implementations
	template<typename TActor>
	WeakPtr<TActor> World::SpawnActor()
	{
		SharedPtr<TActor> Actor{ new TActor{this} };
		m_PendingActors.push_back(Actor);

		return Actor;
	}
}