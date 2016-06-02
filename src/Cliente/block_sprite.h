#ifndef _BLOCK_SPRITE_H_
#define _BLOCK_SPRITE_H_

#include "Sprite.h"

class Block_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Block_sprite(SDL_Renderer *r, const char* file);
};

#endif
