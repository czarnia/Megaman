#include "Renderer.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

#define BACKGROUND 1
#define CAMSPEEDX 5
#define NON_STATIC 0
#define STATIC 1
#define FRONT 1
#define BACK 0
#define LEFT 1
#define RIGHT 0

#define LAYER_NUMBER 2

Renderer::Renderer(Window *window):
    window(window),
    camX(0),
    camY(0)
{
    renderer = SDL_CreateRenderer(window->get_window(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    map_size.first = 0;
    map_size.second = 0;
    std::map<int,Sprite*> slayer1;
    std::map<int,Sprite*> slayer2;
    std::map<int,Sprite*> layer1;
    std::map<int,Sprite*> layer2;
    sprites.push_back(layer1);
    sprites.push_back(layer2);
    static_sprites.push_back(slayer1);
    static_sprites.push_back(slayer2);
}

SDL_Renderer* Renderer::get_renderer(){
    return renderer;
}

void Renderer::addSprite(int objectid, Sprite* spr, int layer, int locked){
    if (!locked){
        while(sprites[layer].find(objectid) != sprites[layer].end()){
            objectid += 1;
        }
        sprites[layer].insert(std::pair<int,Sprite*>(objectid,spr));
    }else{
        while(static_sprites[layer].find(objectid) != static_sprites[layer].end()){
            objectid += 1;
        }
        static_sprites[layer].insert(std::pair<int,Sprite*>(objectid,spr));
    }
}

void Renderer::clearSprites(){
    /// Limpio sprites
    for(int i = 0; i < LAYER_NUMBER; i++){
        std::map<int,Sprite*>::iterator it = sprites[i].begin();
        for(; it != sprites[i].end() ; ++it)
            delete it->second;
        sprites[i].clear();
    }
    for(int i = 0; i < LAYER_NUMBER; i++){
        std::map<int,Sprite*>::iterator it = static_sprites[i].begin();
        for(; it != static_sprites[i].end() ; ++it)
            delete it->second;
        static_sprites[i].clear();
    }
}

void Renderer::setMapSize(int width, int height){
    map_size.first = width;
    map_size.second = height;
}

void Renderer::updateCamPos(int player){
    int px = sprites[FRONT][player]->get_rectangle()->x;
    if((px > (window->get_width()/2) + camX) && (camX+window->get_width() < map_size.first)){
        camX += CAMSPEEDX;
    }
    if((px < window->get_width()/2+camX) && (camX > 0)){
        camX -= CAMSPEEDX;
    }
}

void Renderer::clear(){
    SDL_RenderClear(renderer);
}

void Renderer::erase(int key){
    std::map<int,Sprite*>::iterator it;
    it = sprites[FRONT].find(key);
    if( it != sprites[FRONT].end() ){
        delete it->second;
        sprites[FRONT].erase(it);
    }
}

void Renderer::erase(int x, int y){
    for(int i = 0; i<LAYER_NUMBER; i++){
        std::map<int,Sprite*>::iterator it = sprites[i].begin();
        for(; it != sprites[i].end(); ++it){
            if((it->second->getPosX() == x))
                if((it->second->getPosY() == y))
                    erase(it->first);
        }
    }
    for(int i = 0; i<LAYER_NUMBER; i++){
        std::map<int,Sprite*>::iterator it = static_sprites[i].begin();
        for(; it != static_sprites[i].end(); ++it){
            if((it->second->getPosX() == x))
                if((it->second->getPosY() == y))
                    erase(it->first);
        }
    }
}

bool Renderer::find(int key){
    bool found = false;
    std::map<int,Sprite*>::iterator it;
    for(int i = 0; i < LAYER_NUMBER; i++){
        it = sprites[i].find(key);
        if( it != sprites[i].end() )
            found = true;
    }
    if (found)
        return true;
    else
        return false;
}

void Renderer::draw(Sprite *spr, int lockedToScreen){
    if(!lockedToScreen){
        auxRect = *(spr->get_rectangle());
        auxRect.x = spr->getPosX() - camX;
        auxRect.y = spr->getPosY() - camY;
        if (spr->get_direction() == LEFT)
            SDL_RenderCopyEx(renderer, spr->get_texture(), spr->get_crop(), &auxRect, 0, NULL, SDL_FLIP_HORIZONTAL);
        else
            SDL_RenderCopy(renderer, spr->get_texture(), spr->get_crop(), &auxRect);
    }else{
        if (spr->get_direction() == LEFT)
            SDL_RenderCopyEx(renderer, spr->get_texture(), spr->get_crop(), &auxRect, 0, NULL, SDL_FLIP_HORIZONTAL);
        else
            SDL_RenderCopy(renderer, spr->get_texture(), spr->get_crop(), spr->get_rectangle());
    }
}

void Renderer::drawAll(){
    std::map<int,Sprite*>::iterator it = static_sprites[BACK].begin();
    for(; it != static_sprites[BACK].end(); ++it){
        if(it->second)
            draw(it->second, STATIC);
    }
    it = sprites[BACK].begin();
    for(; it != sprites[BACK].end(); ++it){
        if(it->second)
            draw(it->second, NON_STATIC);
    }
    it = sprites[FRONT].begin();
    for(; it != sprites[FRONT].end(); ++it){
        if(it->second)
            draw(it->second, NON_STATIC);
    }
    it = static_sprites[FRONT].begin();
    for(; it != static_sprites[FRONT].end(); ++it){
        if(it->second)
            draw(it->second, STATIC);
    }
}

bool Renderer::ocupied(int x, int y){
    bool ocupied = false;
    for(int i = 0 ; i<LAYER_NUMBER; i++){
        std::map<int,Sprite*>::iterator it = sprites[i].begin();
        it = sprites[i].begin();
        for(; it != sprites[i].end(); ++it){
            if((it->second->getPosX() == x))
                if((it->second->getPosY() == y))
                    ocupied = true;
        }
    }

    if(ocupied){
        return true;
    }else{
        return false;
    }
}

int Renderer::pressed(int x, int y){
    for(int i = 0; i<LAYER_NUMBER; i++){
        std::map<int,Sprite*>::iterator it = static_sprites[i].begin();
        for(; it != static_sprites[i].end(); ++it){
            if(it->first != BACKGROUND && it->first != BACKGROUND+1){
                Sprite *current = it->second;
                if ((x > current->getPosX()) && (x < current->getPosX() + current->getWidth()))
                    if ((y > current->getPosY()) && (y < current->getPosY() + current->getHeight()))
                        return it->first;
            }
        }
    }
    return 0;
}

void Renderer::present(){
    SDL_RenderPresent(renderer);
}

Renderer::~Renderer(){
    clearSprites();
    SDL_DestroyRenderer(renderer);
}
