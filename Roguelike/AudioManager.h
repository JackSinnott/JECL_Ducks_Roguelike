#ifndef AUDIO_MANAGER_INCLUDE
#define AUDIO_MANAGER_INCLUDE

#include <SFML/Audio.hpp>
#include <memory>
#include <unordered_map>
#include <string>
#include "ResourceAllocator.h"
#include "AudioAsset.h"
#include <iostream>

/// <summary>
/// Loads Music to unique pointers and has the capabilities of deleting the resources.
/// </summary>
class AudioManager : public ResourceAllocator<AudioManager, std::shared_ptr<Audio>>
{
public:
	/// <summary>
	/// Function used to add a specific Audio to the map
	/// </summary>
	/// <param name="filePath">path to the audio</param>
	/// <param name="name">the name associated with the sound</param>
	/// <returns>if the sound was added correctly</returns>
	static bool AddSound(const std::string& filePath, const std::string& name, AudioType type)
	{
		if (!m_sounds.count(name))
		{
			auto pAudio = std::make_shared<Audio>(type, filePath);
			m_sounds.try_emplace(name, pAudio);
			return true;
		}
		return false;
	}

	static void Play(std::string name)
	{
		if (m_sounds.count(name))
		{
			if (m_sounds.at(name).get()->getType() == AudioType::MUSIC)
			{
				if (!m_sounds.at(name).get()->isPlaying())
					m_sounds.at(name).get()->play();
			}
			else
				m_sounds.at(name).get()->play();
		}
		else
			std::cout << "Sound Doesn't Exist\n";
	}

	static void Pause(std::string name)
	{
		if (m_sounds.count(name))
		{
			m_sounds.at(name).get()->pause();
		}
	}

	static void Stop(std::string name)
	{
		if (m_sounds.count(name))
		{
			m_sounds.at(name).get()->stop();
		}
	}

	static void SetVolume(AudioType t_type, float t_volume)
	{
		for (auto& audio : m_sounds)
		{
			if (audio.second->getType() == t_type)
				audio.second->setVolume(t_volume);
		}
	}

	static bool isPlaying(std::string name)
	{
		if (m_sounds.count(name))
		{
			return m_sounds.at(name).get()->isPlaying();
		}
		return false;
	}

	/// <summary>
	/// We may not need this as the game is small on entity types but I said I'd include it in case
	/// </summary>
	static void Collectgarbage() // delete resources not being used.
	{
		for (auto i = m_sounds.begin(); i != m_sounds.end(); )
		{
			if (i->second.unique()) // If there is only one owner it must only belong to this texture manager
			{
				i = m_sounds.erase(i); // So we can erase it. I must be assigned the empty memory or it will be deleted
			}
			else
			{
				++i; // Stay looking for unused textures
			}
		}
	}
private:
	static std::unordered_map<std::string, std::shared_ptr<Audio>> m_sounds;

};


#endif // !BUFFER_MANAGER_H