#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <SDL2/SDL_mixer.h>

class Sample{
    private:
        Mix_Chunk* sound;
    public:
        Sample();
        ~Sample();
};

#endif // _SAMPLE_H_
