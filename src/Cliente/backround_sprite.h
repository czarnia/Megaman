#ifndef _BACKROUND_SPRITE_H_
#define _BACKROUND_SPRITE_H_

#include "Sprite.h"

class Backround_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Backround_sprite(SDL_Renderer *r, const char* file);
};


#endif // _BACKROUND_SPRITE_H_
