#include <iostream>
#include "music_player.h"

MusicPlayer::MusicPlayer() : m_state(new StoppedState()) {}
MusicPlayer::~MusicPlayer() { delete m_state; }

void MusicPlayer::play()     { m_state->play(this); }
void MusicPlayer::pause()    { m_state->pause(this); }
void MusicPlayer::stop()     { m_state->stop(this); }

void MusicPlayer::setState(State state)
{
    std::cout << "Changing from " << m_state->getName() << " to ";
    
    delete m_state;
    switch (state)
    {
        case STOPPED: { m_state = new StoppedState(); break; }
        case PLAYING: { m_state = new PlayingState(); break; }
        case PAUSED: { m_state = new PausedState(); break; }
    };                          
    
    std::cout << m_state->getName() << " state\n";
}
