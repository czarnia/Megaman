#ifndef _CHARACTER_SPRITE_H_
#define _CHARACTER_SPRITE_H_

#include "Sprite.h"

class Character_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Character_sprite(SDL_Renderer *r, const char* file);
};

#endif // _CHARACTER_SPRITE_H_
