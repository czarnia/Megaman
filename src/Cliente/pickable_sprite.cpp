#include "pickable_sprite.h"

Pickable_sprite::Pickable_sprite(SDL_Renderer *r, const char* file, bool big):
    Sprite(r,file)
{
    if(big){
        width = 15;
        height = 15;
    }else{
        width = 10;
        height = 10;
    }
    rectangle.w = Pickable_sprite::width;
    rectangle.h = Pickable_sprite::height;
    crop = NULL;
}


