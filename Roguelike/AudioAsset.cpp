#include "AudioAsset.h"

Audio::Audio(AudioType t_type, std::string t_path) : m_type(t_type)
{
	m_buffer.loadFromFile(t_path);

	m_audio.setBuffer(m_buffer);
}

Audio::~Audio()
{
}

void Audio::play()
{
	m_audio.play();
}

void Audio::pause()
{
	m_audio.pause();
}

void Audio::stop()
{
	m_audio.pause();
}

void Audio::setVolume(float t_volume)
{
	m_audio.setVolume(t_volume);
}

bool Audio::isPlaying()
{
	return m_audio.getStatus() == sf::SoundSource::Status::Playing;
}
