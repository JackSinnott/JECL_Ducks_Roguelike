#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>>
#include <unordered_map>
#include <string>
#include "ResourceAllocator.h"

/// <summary>
/// Loads textures to unique pointers and has the capabilities of deleting the resources. Use as a template for other resources
/// </summary>
class TextureManager : public ResourceAllocator<TextureManager, std::shared_ptr<sf::Texture>>
{
public:
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
	/// We may not need this as the game is small on entity types but I said I'd include it in case
	/// </summary>
	static void Collectgarbage() // delete resources not being used.
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
	static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> texturePtrs;
};

#endif // !TEXTURE_MANAGER_H
