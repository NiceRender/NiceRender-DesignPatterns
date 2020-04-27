#pragma once

#include <string>
#include "music_player.h"

class MusicPlayer;

class MusicPlayerState
{
    public:
        MusicPlayerState(std::string name);
        virtual ~MusicPlayerState();
        virtual void play(MusicPlayer* player);
        virtual void pause(MusicPlayer* player);
        virtual void stop(MusicPlayer* player);
        std::string getName();
    
    private:
        std::string m_name;
};

class PlayingState : public MusicPlayerState
{
    public:
        PlayingState();
        void pause(MusicPlayer* player);
        void stop(MusicPlayer* player);
};

class PausedState : public MusicPlayerState
{
    public:
        PausedState();
        void play(MusicPlayer* player);
        void stop(MusicPlayer* player);
};

class StoppedState : public MusicPlayerState
{
    public:
        StoppedState();
        void play(MusicPlayer* player);
};
