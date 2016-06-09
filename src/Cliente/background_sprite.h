#ifndef _BACKGROUND_SPRITE_H_
#define _BACKGROUND_SPRITE_H_

#include "Sprite.h"

class Background_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Background_sprite(SDL_Renderer *r, const char* file);
};


#endif // _BACKGROUND_SPRITE_H_
