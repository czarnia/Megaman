#ifndef _BOSS_ICON_SPRITE_H_
#define _BOSS_ICON_SPRITE_H_

#include "Sprite.h"

class Boss_icon_sprite: public Sprite{
    public:
        static int width;
        static int height;
        Boss_icon_sprite(SDL_Renderer *r, const char* file);
};

#endif // _CHARACTER_SPRITE_H_

