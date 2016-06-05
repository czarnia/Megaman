#include "Renderer.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Renderer::Renderer(SDL_Window *w): camX(0),camY(0){
    renderer = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Renderer* Renderer::get_renderer(){
    return renderer;
}

void Renderer::clearSprites(){
    /// Limpio sprites
    std::map<int,Sprite*>::iterator it = sprites.begin();
    for(; it != sprites.end() ; ++it)
        delete it->second;
    sprites.clear();
    /// Limpio mapa
    it = map_sprites.begin();
    for(; it != map_sprites.end() ; ++it)
        delete it->second;
    map_sprites.clear();
}

void Renderer::clear(){
    SDL_RenderClear(renderer);
}

void Renderer::erase(int key){
    std::map<int,Sprite*>::iterator it;
    it = sprites.find(key);
    if( it != sprites.end() ){
        delete it->second;
        sprites.erase(it);
    }
    it = map_sprites.find(key);
    if( it != map_sprites.end() ){
        delete it->second;
        map_sprites.erase(it);
    }
}

void Renderer::erase(int x, int y){
    std::map<int,Sprite*>::iterator it = map_sprites.begin();
    it = map_sprites.begin();
    for(; it != map_sprites.end(); ++it){
        if((it->second->getPosX() == x))
            if((it->second->getPosY() == y))
                erase(it->first);
    }
    it = sprites.begin();
    for(; it != sprites.end(); ++it){
        if((it->second->getPosX() == x))
            if((it->second->getPosY() == y))
                erase(it->first);
    }
}

bool Renderer::find(int key){
    std::map<int,Sprite*>::iterator it;
    it = sprites.find(key);
    if( it != sprites.end() )
        return true;
    else
        return false;
}

void Renderer::draw(Sprite *spr){
    auxRect = *(spr->get_rectangle());
    auxRect.x = spr->getPosX() - camX;
    auxRect.y = spr->getPosY() - camY;
    SDL_RenderCopy(renderer, spr->get_texture(), spr->get_crop(), &auxRect);
}

void Renderer::present(){
    SDL_RenderPresent(renderer);
}

void Renderer::addSprite(int objectid, Sprite* spr){
    while(sprites.find(objectid) != sprites.end()){
        objectid += 1;
    }
    sprites.insert(std::pair<int,Sprite*>(objectid,spr));
}

void Renderer::setMapSize(int width, int height){
    map_size.first = width;
    map_size.second = height;
}

void Renderer::addMapSprite(int objectid, Sprite* spr){
    while(map_sprites.find(objectid) != map_sprites.end()){
        objectid += 1;
    }
    map_sprites.insert(std::pair<int,Sprite*>(objectid,spr));
}

void Renderer::drawAll(){
    std::map<int,Sprite*>::iterator it = sprites.begin();
    for (; it != sprites.end() ; ++it){
        draw(it->second);
    }
    it = map_sprites.begin();
    for (; it != map_sprites.end() ; ++it){
        draw(it->second);
    }
}

bool Renderer::ocupied(int x, int y){
    bool ocupied = false;
    std::map<int,Sprite*>::iterator it = map_sprites.begin();
    it = map_sprites.begin();
    for(; it != map_sprites.end(); ++it){
        if((it->second->getPosX() == x))
            if((it->second->getPosY() == y))
                ocupied = true;
    }

    it = sprites.begin();
    for(; it != sprites.end(); ++it){
        if((it->second->getPosX() == x))
            if((it->second->getPosY() == y))
                ocupied = true;
    }


    if(ocupied){
        return true;
    }else{
        return false;
    }
}

Renderer::~Renderer(){
    clearSprites();
    SDL_DestroyRenderer(renderer);
}
