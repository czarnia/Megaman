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

void Renderer::draw(Sprite *spr){
    std::cout<<spr->getPosX()<<","<<spr->getPosY();
    std::cout<<"    "<<spr->get_rectangle()->w<<","<<spr->get_rectangle()->h<<std::endl;
    SDL_RenderCopy(renderer, spr->get_texture(), NULL, spr->get_rectangle());
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
    std::cout<<map_sprites.size()<<std::endl;
    std::cout<<sprites.size()<<std::endl;
    std::map<int,Sprite*>::iterator it = sprites.begin();
    for (; it != sprites.end() ; ++it){
        draw(it->second);
    }
    it = map_sprites.begin();
    for (; it != map_sprites.end() ; ++it){
        draw(it->second);
    }
}

Renderer::~Renderer(){
    clearSprites();
    SDL_DestroyRenderer(renderer);
}
