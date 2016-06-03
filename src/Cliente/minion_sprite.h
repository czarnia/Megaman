#ifndef _MINION_SPRITE_H_
#define _MINION_SPRITE_H_

#include "Sprite.h"

class Minion_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Minion_sprite(SDL_Renderer *r, const char* file);
};

#endif

