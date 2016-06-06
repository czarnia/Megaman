#ifndef _SELECTOR_SPRITE_H_
#define _SELECTOR_SPRITE_H_

#include "Sprite.h"

class Selector_sprite: public Sprite{
    public:
        static int width;
        static int height;
        Selector_sprite(SDL_Renderer *r, const char* file);
};

#endif // _CHARACTER_SPRITE_H_


