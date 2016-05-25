#include "Sprite.h"
#include <SDL2/SDL_image.h>

Sprite::Sprite(SDL_Renderer *r, const char *file){
    texture = IMG_LoadTexture(r, file);
}

void Sprite::set_Sprite(int posx, int posy, int width,
                        int height, int origin,
                        int cropw, int croph){
    if (origin){
        rectangle.x = posx - width/2;
        rectangle.y = posy - height/2;
        rectangle.w = width;
        rectangle.h = height;
    }else{
        rectangle.x = posx;
        rectangle.y = posy;
        rectangle.w = width;
        rectangle.h = height;
    }
    origin = origin;
    crop.x = 0;
    crop.y = 0;
    crop.w = width/2;
    crop.h = height/2;
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




