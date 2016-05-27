#include "Renderer.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>

#define MAPA 1
#define BARRA_VIDA 2
#define BARRA_ENERGIA 3
#define VIDAS 4
#define VICTORIA 5
#define KO 6

Renderer::Renderer(SDL_Window *w){
    renderer = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
    //loadTextures();
}

SDL_Renderer* Renderer::get_renderer(){
    return renderer;
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

void Renderer::add(std::string object, Sprite* spr){
    sprites[object] = spr;
}

void Renderer::drawAll(){
    std::map<std::string,Sprite*>::iterator it = sprites.begin();
    for (; it != sprites.end() ; ++it){
        draw(it->second);
    }
}

void Renderer::execute(int command, int option, std::pair<int,int> coord){

    switch (command){
        case MAPA:
            //si no existe el sprite lo creo
            //si existe seteo posicion
            break;
        case BARRA_VIDA:
            break;
        case BARRA_ENERGIA:
            break;
        case VIDAS:
            break;
        case VICTORIA:
            break;
        case KO:
            break;
    }

}


Renderer::~Renderer(){
    SDL_DestroyRenderer(renderer);
}
