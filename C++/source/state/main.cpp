#include "music_player.h"

int main()
{
    MusicPlayer player;
    
    // Correct
    player.play();
    player.pause();
    player.stop();
    
    // Error
    player.stop();
    player.pause();
}
