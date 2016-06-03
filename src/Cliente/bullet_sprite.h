#ifndef _BULLET_SPRITE_H
#define _BULLET_SPRITE_H

#include "Sprite.h"

class Bullet_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Bullet_sprite(SDL_Renderer *r, const char* file);
};

#endif

