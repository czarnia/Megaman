#include "block_sprite.h"

int Block_sprite::width = 60;
int Block_sprite::height = 60;

Block_sprite::Block_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Block_sprite::width;
    rectangle.h = Block_sprite::height;
    crop = NULL;
}
