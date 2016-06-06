#include "boss_icon_sprite.h"

int Boss_icon_sprite::width = 60;
int Boss_icon_sprite::height = 60;

Boss_icon_sprite::Boss_icon_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Boss_icon_sprite::width;
    rectangle.h = Boss_icon_sprite::height;
    crop = NULL;
}

