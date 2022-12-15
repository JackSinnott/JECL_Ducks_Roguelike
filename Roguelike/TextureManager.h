#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>
#include "ResourceAllocator.h"

/// <summary>
/// Class that loads textures to unique pointers and has the capabilities of deleting them.
/// Derives from ResourceAllocator. 
/// </summary>

class TextureManager : public ResourceAllocator<TextureManager, std::shared_ptr<sf::Texture>>
{
public:

	/// <summary>
	/// Searches for a new texture in the project's files, loads it and returns it.
	/// </summary>
	/// <param name="name">String that is the path to what is to be acquired.</param>
	/// <returns>A shared_ptr to the loaded texture.</returns>
	static std::shared_ptr<sf::Texture> Acquire(const std::string& name)
	{
		const auto i = texturePtrs.find(name);
		if (i != texturePtrs.end()) // is the iterator valid
		{
			return i->second; // return ptr to texture
		}
		else // load texture
		{
			auto pTex = std::make_shared<sf::Texture>();
			pTex->loadFromFile(name);
			texturePtrs.insert({ name,pTex });
			return pTex;
		}
	}


	/// <summary>
	/// deletes textures not being used, saving memory.
	/// </summary>
	static void Collectgarbage()
	{
		for (auto i = texturePtrs.begin(); i != texturePtrs.end(); )
		{
			if (i->second.unique()) // If there is only one owner it must only belong to this texture manager
			{
				i = texturePtrs.erase(i); // So we can erase it. I must be assigned the empty memory or it will be deleted
			}
			else
			{
				++i; // Stay looking for unused textures
			}
		}
	}
private:

	/// <summary>
	/// A collection of all the shared_ptrs to the textures.
	/// </summary>
	static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> texturePtrs;
};

#endif // !TEXTURE_MANAGER_H
