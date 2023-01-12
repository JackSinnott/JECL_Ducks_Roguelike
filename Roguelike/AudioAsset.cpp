#include "AudioAsset.h"

/// <summary>
/// Overloaded constructor.
/// </summary>
/// <param name="t_type">The type of sound this one will be.</param>
/// <param name="t_path">The path of where the audio file is.</param>
Audio::Audio(AudioType t_type, std::string t_path) : m_type(t_type)
{
	m_buffer.loadFromFile(t_path);

	m_audio.setBuffer(m_buffer);
}

/// <summary>
/// Default deconstructor.
/// </summary>
Audio::~Audio()
{
}

/// <summary>
/// Plays the audio.
/// </summary>
void Audio::play()
{
	m_audio.play();
}

/// <summary>
///Pauses the audio, if its playing.
/// </summary>
void Audio::pause()
{
	m_audio.pause();
}

/// <summary>
/// Stops the audio, if its playing.
/// </summary>
void Audio::stop()
{
	m_audio.pause();
}

/// <summary>
/// Changes the volume of this sound.
/// </summary>
/// <param name="t_volume">The volume that the audio will be set to.</param>
void Audio::setVolume(float t_volume)
{
	m_audio.setVolume(t_volume);
}

/// <summary>
/// Returns whether the audio is playing or not.
/// </summary>
/// <returns>Is the audio playing?</returns>
bool Audio::isPlaying()
{
	return m_audio.getStatus() == sf::SoundSource::Status::Playing;
}
