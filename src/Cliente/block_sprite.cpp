#include "block_sprite.h"

/// RAROOOOOOOOOOOOOOO
int Block_sprite::width = 30;
int Block_sprite::height = 30;

Block_sprite::Block_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Block_sprite::width;
    rectangle.h = Block_sprite::height;
}
