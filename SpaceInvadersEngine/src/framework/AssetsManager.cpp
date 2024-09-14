#include "framework/AssetsManager.h"

namespace si
{
	// Initializes static member variable
	UniquePtr<AssetsManager> AssetsManager::m_AssetsManager = nullptr;

	AssetsManager::AssetsManager()
		: m_RootDirectory()
	{}

	AssetsManager& AssetsManager::Get()
	{
		if (m_AssetsManager == nullptr)
		{
			m_AssetsManager = std::move(UniquePtr<AssetsManager>{new AssetsManager});
		}

		return *m_AssetsManager;
	}

	SharedPtr<sf::Texture> AssetsManager::LoadTexture(const std::string& Path)
	{
		// If already exists, returns existing texture
		auto TexturesMapIterator = m_TexturesMap.find(Path);
		if (TexturesMapIterator != m_TexturesMap.end())
		{
			return TexturesMapIterator->second;
		}

		SharedPtr<sf::Texture> Texture{new sf::Texture};

		// If texture path is valid, inserts texture into map and returns texture
		bool IsLoaded = Texture->loadFromFile(m_RootDirectory + Path);
		if (IsLoaded)
		{
			m_TexturesMap.insert({Path, Texture});
			return Texture;
		}

		// If texture path is not valid, returns nullptr
		return SharedPtr<sf::Texture> {nullptr};
	}

	void AssetsManager::CleanCycle()
	{
		for (auto iterator = m_TexturesMap.begin(); iterator != m_TexturesMap.end();)
		{
			// If texture is not being used anymore (if the texture pointer in the map is the only one), deletes texture
			if (iterator->second.unique())
			{
				iterator = m_TexturesMap.erase(iterator);
				continue;
			}

			++iterator;
		}
	}

	void AssetsManager::SetAssetsRootDirectory(const std::string& RootDirectory)
	{
		m_RootDirectory = RootDirectory;
	}
}