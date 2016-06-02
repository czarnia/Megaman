#include "backround_sprite.h"

int Backround_sprite::width = 640;
int Backround_sprite::height = 480;

Backround_sprite::Backround_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Backround_sprite::width;
    rectangle.h = Backround_sprite::height;
}
