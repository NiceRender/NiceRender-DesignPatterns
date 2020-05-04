#include "music_player.h"

int main()
{
    MusicPlayer player;

    player.play();  // Correct
    player.pause(); // Correct
    player.stop();  // Correct

    player.stop();  // Error
    player.pause(); // Error
}
