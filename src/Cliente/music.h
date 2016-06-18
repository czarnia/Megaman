#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <SDL2/SDL_mixer.h>
#include <string>

class Music{
    private:
        Mix_Music* piece;
    public:
        Music();
        void play();
        void changeTrack(std::string file);
        void stop();
        ~Music();
};

#endif
