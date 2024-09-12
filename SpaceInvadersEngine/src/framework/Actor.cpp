#include "framework/Actor.h"

#include "framework/AssetsManager.h"
#include "framework/Core.h"
#include "framework/MathUtility.h"
#include "framework/World.h"

namespace si
{
	Actor::Actor(World* OwningWorld, const std::string& TexturePath)
		: m_OwningWorld(OwningWorld), m_HasBegunPlay(false), m_Sprite(), m_Texture()
	{
		if (TexturePath == "")
		{
			return;
		}

		SetTexture(TexturePath);
	}

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

	void Actor::TickInternal(float DeltaTime)
	{
		if (IsDestructionPending())
		{
			return;
		}

		Tick(DeltaTime);
	}

	void Actor::BeginPlay()
	{
		LOG("Actor begun play");
	}

	void Actor::Tick(float DeltaTime)
	{
		LOG("Actor ticking at %f framerate", 1.f / DeltaTime);
	}

	void Actor::SetTexture(const std::string& Path)
	{
		m_Texture = AssetsManager::Get().LoadTexture(Path);
		if (m_Texture == nullptr)
		{
			return;
		}

		m_Sprite.setTexture(*m_Texture);
		int TextureWidth = m_Texture->getSize().x;
		int TextureHeight = m_Texture->getSize().y;
		m_Sprite.setTextureRect(sf::IntRect(sf::Vector2i(), sf::Vector2i(TextureWidth, TextureHeight)));

		CenterOrigin();
	}

	void Actor::Render(sf::RenderWindow& Window)
	{
		Window.draw(m_Sprite);
	}

	sf::Vector2f Actor::GetPosition() const
	{
		return m_Sprite.getPosition();
	}

	float Actor::GetRotation() const
	{
		return m_Sprite.getRotation();
	}

	sf::Vector2f Actor::GetForwardDirection() const
	{
		return ConvertRotationToVector(GetRotation());
	}

	sf::Vector2f Actor::GetRightDirection() const
	{
		return ConvertRotationToVector(GetRotation() + 90.f);
	}

	void Actor::SetPosition(const sf::Vector2f& Position)
	{
		m_Sprite.setPosition(Position);
	}

	void Actor::SetRotation(float Rotation)
	{
		m_Sprite.setRotation(Rotation);
	}

	void Actor::AddPositionOffset(const sf::Vector2f& Offset)
	{
		SetPosition(GetPosition() + Offset);
	}

	void Actor::AddRotationffset(float Offset)
	{
		SetRotation(GetRotation() + Offset);
	}

	void Actor::CenterOrigin()
	{
		sf::FloatRect Bounds = m_Sprite.getGlobalBounds();
		m_Sprite.setOrigin(Bounds.width / 2.f, Bounds.height / 2.f);
	}
}