#ifndef _PICKABLE_SPRITE_H_
#define _PICKABLE_SPRITE_H_

#include "Sprite.h"

class Pickable_sprite: public Sprite{
    public:
        Pickable_sprite(SDL_Renderer *r, const char* file, bool big);
        int width;
        int height;
};

#endif
