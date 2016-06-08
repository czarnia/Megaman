#include "background_sprite.h"

int Background_sprite::width = 640;
int Background_sprite::height = 480;

Background_sprite::Background_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Background_sprite::width;
    rectangle.h = Background_sprite::height;
    crop = NULL;
}
