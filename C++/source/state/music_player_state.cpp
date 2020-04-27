#include <iostream>
#include "music_player_state.h"

// MusicPlayerState

MusicPlayerState::MusicPlayerState(std::string name) : m_name(name) {}
MusicPlayerState::~MusicPlayerState() {}
std::string MusicPlayerState::getName() { return m_name; }

void MusicPlayerState::play(MusicPlayer*)
{
	std::cout << "Illegal state transition from " << getName() << " to Playing\n";
}

void MusicPlayerState::pause(MusicPlayer*)
{
	std::cout << "Illegal state transition from " << getName() << " to Paused\n";
}

void MusicPlayerState::stop(MusicPlayer*)
{
	std::cout << "Illegal state transition from " << getName() << " to Stopped\n";
}

// PlayingState

PlayingState::PlayingState() : MusicPlayerState(std::string("Playing")) {}
void PlayingState::pause(MusicPlayer* player) { player->setState(MusicPlayer::PAUSED); }
void PlayingState::stop(MusicPlayer* player) { player->setState(MusicPlayer::STOPPED); }

// PausedState

PausedState::PausedState() : MusicPlayerState(std::string("Paused")) {}
void PausedState::play(MusicPlayer* player) { player->setState(MusicPlayer::PLAYING); }
void PausedState::stop(MusicPlayer* player) { player->setState(MusicPlayer::STOPPED); }

// StoppedState

StoppedState::StoppedState() : MusicPlayerState(std::string("Stopped")) {}
void StoppedState::play(MusicPlayer* player) { player->setState(MusicPlayer::PLAYING); }
