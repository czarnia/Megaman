#include "bar_sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>

int Bar_sprite::width = 100;
int Bar_sprite::height = 10;

Bar_sprite::Bar_sprite(SDL_Renderer *r, bool hp)
{
    texture = NULL;
    if (hp){
        for(int i = 0; i < 9; i++){
            std::ostringstream os;
            os << "../sprites/hpbar"<<i<<".8.png";
            std::string file(os.str());
            bar_vector.push_back(IMG_LoadTexture(r, file.c_str()));
        }
    }else{
        for(int i = 0; i < 9; i++){
            std::ostringstream os;
            os << "../sprites/mpbar"<<i<<".8.png";
            std::string file(os.str());
            bar_vector.push_back(IMG_LoadTexture(r, file.c_str()));
        }
    }
    rectangle.w = Bar_sprite::width;
    rectangle.h = Bar_sprite::height;
    ammount = 8;
    crop = NULL;
}

void Bar_sprite::setAmmount(int ammount){
    ammount = ammount;
}

SDL_Texture* Bar_sprite::get_texture(){
    return bar_vector[ammount-1];
}

Bar_sprite::~Bar_sprite(){
    for(int i = 0; i<9; i++){
        SDL_DestroyTexture(bar_vector[i]);
    }
}
