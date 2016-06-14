#include "bar_sprite.h"


int Bar_sprite::width = 100;
int Bar_sprite::height = 10;

Bar_sprite::Bar_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Bar_sprite::width;
    rectangle.h = Bar_sprite::height;
    crop = NULL;
}


