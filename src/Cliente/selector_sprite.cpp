#include "selector_sprite.h"
#include "boss_icon_sprite.h"

int Selector_sprite::width = Boss_icon_sprite::width+10;
int Selector_sprite::height = Boss_icon_sprite::height+10;

Selector_sprite::Selector_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Selector_sprite::width;
    rectangle.h = Selector_sprite::height;
    crop = NULL;
}


