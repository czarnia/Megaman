#ifndef _TEXT_SPRITE_H_
#define _TEXT_SPRITE_H_

#include "Sprite.h"
#include <string>

class Text_sprite: public Sprite{
    private:
    public:
        Text_sprite(SDL_Renderer *r, std::string text, int fontSize);
        ~Text_sprite();
};

#endif // _TEXT_SPRITE_H_
