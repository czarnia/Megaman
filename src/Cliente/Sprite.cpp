#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite(SDL_Renderer *r, const char* file){
    texture = NULL;
    texture = IMG_LoadTexture(r, file);
    if(!texture)
        std::cout<<"No se pudo cargar textura"<<std::endl;
}

void Sprite::set_Sprite(int width, int height,
                        int cropw, int croph){
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = width;
    rectangle.h = height;
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
