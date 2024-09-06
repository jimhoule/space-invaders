#pragma once

#include "framework/Core.h"
#include "framework/Object.h"

#include <SFML/Graphics.hpp>

namespace si
{
	class World;

	class Actor : public Object
	{
	public:
		Actor(World* OwningWorld, const std::string& TexturePath = "");
		virtual ~Actor();

		void BeginPlayInternal();
		void TickInternal(float DeltaTime);
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
		void SetTexture(const std::string& Path);
		void Render(sf::RenderWindow& Window);

	private:
		World* m_OwningWorld;
		bool m_HasBegunPlay;
		sf::Sprite m_Sprite;
		SharedPtr<sf::Texture> m_Texture;
	};
}