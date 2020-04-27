#pragma once

#include "music_player_state.h"

class MusicPlayerState;

class MusicPlayer
{
    public:
        enum State { STOPPED, PLAYING, PAUSED };
    
        MusicPlayer();
        ~MusicPlayer();

        void play();
        void pause();
        void stop();
        void setState(State state);
    
    private:
        MusicPlayerState* m_state;
};

