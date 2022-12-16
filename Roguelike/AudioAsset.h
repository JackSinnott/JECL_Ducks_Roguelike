#ifndef AUDIO_ASSET_INCLUDE
#define AUDIO_ASSET_INCLUDE

#include <SFML/Audio.hpp>

/// <summary>
/// The type of sounds that could be played in-game.
/// </summary>
enum class AudioType
{
	MUSIC,
	SFX
};

/// <summary>
/// Audio class - This will handle the start, stop, pause and playing of a sound.
/// </summary>
class Audio
{
public:
	Audio(AudioType, std::string t_path);
	~Audio();

	void play();

	void pause();

	void stop();

	void setVolume(float t_volume);

	const AudioType getType() { return m_type; }

	bool isPlaying();
private:
	/// The buffer for the sound objects.
	sf::SoundBuffer m_buffer;

	/// The type of audio that will be player.
	AudioType m_type;

	/// The audio itself.
	sf::Sound m_audio;
};

#endif