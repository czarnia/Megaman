#ifndef _BLOCK_SPRITE_H_
#define _BLOCK_SPRITE_H_

#include "Sprite.h"

class Block_sprite: public Sprite{
    public:
        Block_sprite(SDL_Renderer *r, const char* file);
        static int width;
        static int height;
};

#endif
