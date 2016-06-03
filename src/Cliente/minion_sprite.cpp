#include "minion_sprite.h"


int Minion_sprite::width = 30;
int Minion_sprite::height = 30;

Minion_sprite::Minion_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Minion_sprite::width;
    rectangle.h = Minion_sprite::height;
}

