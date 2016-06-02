#ifndef _CHARACTER_SPRITE_H_
#define _CHARACTER_SPRITE_H_

#include "Sprite.h"

class Main_character: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Main_character(SDL_Renderer *r, const char* file);
};

#endif // _CHARACTER_SPRITE_H_
