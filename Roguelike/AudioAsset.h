#ifndef AUDIO_ASSET_INCLUDE
#define AUDIO_ASSET_INCLUDE

#include <SFML/Audio.hpp>

enum class AudioType
{
	MUSIC,
	SFX
};

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
	sf::SoundBuffer m_buffer;
	AudioType m_type;
	sf::Sound m_audio;
};

#endif