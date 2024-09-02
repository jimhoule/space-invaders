#pragma once

#include "framework/Object.h"

namespace si
{
	class World;

	class Actor : public Object
	{
	public:
		Actor(World* OwningWorld);
		virtual ~Actor();

		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);

	private:
		World* m_OwningWorld;
		bool m_HasBegunPlay;
	};
}