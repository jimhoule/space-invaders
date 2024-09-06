#pragma once

#include "framework/Core.h"

#include <SFML/Graphics.hpp>

namespace si
{
	class AssetsManager
	{
	public:
		static AssetsManager& Get();
		SharedPtr<sf::Texture> LoadTexture(const std::string& Path);

	protected:
		AssetsManager();

	private:
		static UniquePtr<AssetsManager> m_AssetsManager;
		Dictionary<std::string, SharedPtr<sf::Texture>> m_TexturesMap;
	};
}