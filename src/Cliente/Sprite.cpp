#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite(SDL_Renderer *r, const char* file){
    texture = NULL;
    texture = IMG_LoadTexture(r, file);
    if(!texture)
        std::cout<<"No se pudo cargar textura"<<std::endl;
}


SDL_Rect* Sprite::get_rectangle(){
    return &rectangle;
}

SDL_Texture* Sprite::get_texture(){
    return texture;
}

SDL_Rect* Sprite::get_crop(){
    return &crop;
}

int Sprite::getPosX(){
    return rectangle.x;
}
int Sprite::getPosY(){
    return rectangle.y;
}

void Sprite::setPosX(int x){
    rectangle.x = x;
}

void Sprite::setPosY(int y){
    rectangle.y = y;
}

void Sprite::erase(){
    SDL_DestroyTexture(texture);
    texture = NULL;
}

Sprite::~Sprite(){
    if(texture)
        SDL_DestroyTexture(texture);
}

int Backround_sprite::width = 640;
int Backround_sprite::height = 480;

Backround_sprite::Backround_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = width;
    rectangle.h = height;
}

int Block_sprite::width = 15;
int Block_sprite::height = 15;

Block_sprite::Block_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = width;
    rectangle.h = height;
}

