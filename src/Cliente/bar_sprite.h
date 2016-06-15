#ifndef _BAR_SPRITE_H
#define _BAR_SPRITE_H

#include "Sprite.h"

class Bar_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Bar_sprite(SDL_Renderer *r, const char* file);
};

#endif


