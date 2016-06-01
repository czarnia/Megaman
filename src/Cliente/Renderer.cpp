#include "Renderer.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480
#define ORIGIN_CENTERED 1
#define ORIGIN_CORNER 0
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

void Renderer::add(int objectid, Sprite* spr){
    sprites.insert(std::pair<int,Sprite*>(objectid,spr));
}

void Renderer::drawAll(){
    std::map<int,Sprite*>::iterator it = sprites.begin();
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
            Sprite *gameover = new Sprite(renderer, "gameover.jpeg");
            gameover->set_Sprite(WIDTH/4, HEIGHT/4,1,1);
            add(GAMEOVER, gameover);
            break;
        }
    }
}

Renderer::~Renderer(){
    SDL_DestroyRenderer(renderer);
}
