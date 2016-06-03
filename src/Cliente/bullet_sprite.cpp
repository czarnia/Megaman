#include "bullet_sprite.h"


int Bullet_sprite::width = 15;
int Bullet_sprite::height = 15;

Bullet_sprite::Bullet_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Bullet_sprite::width;
    rectangle.h = Bullet_sprite::height;
}

