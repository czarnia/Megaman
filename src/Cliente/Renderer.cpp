#include "Renderer.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>

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
            if(sprites.find(option) != sprites.end()){
                Sprite megaman(renderer, "megaman.jpeg");
                megaman.set_Sprite(40, 50, ORIGIN_CENTERED, 10, 5);
                add(option, &megaman);
            }
            //si existe seteo posicion
            sprites[option]->setPosX(coord.first);
            sprites[option]->setPosY(coord.second);
            break;
        case BARRA_VIDA:
           // sprites[option]->setHP()
            break;
        case BARRA_ENERGIA:
            // sprites[option]->setMP()
            break;
        case VIDAS:
            // sprites[option]->setLifeAmmount()
            break;
        case VICTORIA:{
            Sprite *victory = new Sprite(renderer, "victory.jpeg");
            victory->set_Sprite(WIDTH/4, HEIGHT/4,ORIGIN_CENTERED,1,1);
            add(VICTORIA, victory);
            break;
        }
        case GAMEOVER:{
            Sprite *gameover = new Sprite(renderer, "gameover.jpeg");
            gameover->set_Sprite(WIDTH/4, HEIGHT/4,ORIGIN_CENTERED,1,1);
            add(GAMEOVER, gameover);
            break;
        }
    }
}

Renderer::~Renderer(){
    SDL_DestroyRenderer(renderer);
}
