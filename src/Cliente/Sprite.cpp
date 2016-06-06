#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite(SDL_Renderer *r, const char* file){
    texture = NULL;
    texture = IMG_LoadTexture(r, file);
    crop = NULL;
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
    return crop;
}

int Sprite::getPosX(){
    return rectangle.x;
}

int Sprite::getPosY(){
    return rectangle.y;
}

int Sprite::getWidth(){
    return rectangle.w;
}

int Sprite::getHeight(){
    return rectangle.h;
}

void Sprite::setPosX(int x){
    rectangle.x = x;
}

void Sprite::setPosY(int y){
    rectangle.y = y;
}

void Sprite::setWidth(int w){
    rectangle.w = w;
}

void Sprite::setHeight(int h){
    rectangle.h = h;
}

void Sprite::erase(){
    SDL_DestroyTexture(texture);
    texture = NULL;
}

Sprite::~Sprite(){
    if(texture)
        SDL_DestroyTexture(texture);
}



