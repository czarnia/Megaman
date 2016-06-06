#include "character_sprite.h"

int Character_sprite::width = 30;
int Character_sprite::height = 60;

Character_sprite::Character_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Character_sprite::width;
    rectangle.h = Character_sprite::height;
    crop = NULL;
}
