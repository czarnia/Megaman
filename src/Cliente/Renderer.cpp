#include "Renderer.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

#define MAPA 1
#define BARRA_VIDA 2
#define BARRA_ENERGIA 3
#define VIDAS 4
#define VICTORIA 5
#define GAMEOVER 6

Renderer::Renderer(SDL_Window *w){
    renderer = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Renderer* Renderer::get_renderer(){
    return renderer;
}

void Renderer::clearSprites(){
    std::map<int,Sprite*>::iterator it = sprites.begin();
    for(; it != sprites.end() ; ++it)
        delete it->second;
    sprites.clear();
}

void Renderer::clear(){
    SDL_RenderClear(renderer);
}

void Renderer::draw(Sprite *spr){
    SDL_RenderCopy(renderer, spr->get_texture(), NULL, spr->get_rectangle());
}

void Renderer::present(){
    SDL_RenderPresent(renderer);
}

void Renderer::addSprite(int objectid, Sprite* spr){
    sprites.insert(std::pair<int,Sprite*>(objectid,spr));
}

void Renderer::setMapSize(int width, int height){
    map_size.first = width;
    map_size.second = height;
}

void Renderer::addMapSprite(int objectid, Sprite* spr){
    map_sprites.insert(std::pair<int,Sprite*>(objectid,spr));
}

void Renderer::drawAll(){
    std::map<int,Sprite*>::iterator it = sprites.begin();
    for (; it != sprites.end() ; ++it){
        draw(it->second);
    }
}

void Renderer::execute(int command, int option, std::pair<int,int> coord){
    switch (command){
        case BARRA_VIDA:
            std::cout<<"Recibi nivel de vida: "<<option<<std::endl;
           // sprites[option]->setHP()
            break;
        case BARRA_ENERGIA:
            std::cout<<"Recibi nivel de energia: "<<option<<std::endl;
            // sprites[option]->setMP()
            break;
        case VIDAS:
            std::cout<<"Recibi vidas: "<<option<<std::endl;
            // sprites[option]->setLifeAmmount()
            break;
        case VICTORIA:{
            std::cout<<"Recibi victoria: "<<std::endl;

            break;
        }
        case GAMEOVER:{
            std::cout<<"Recibi gameover: "<<std::endl;
            break;
        }
    }
}

Renderer::~Renderer(){
    clearSprites();
    SDL_DestroyRenderer(renderer);
}
