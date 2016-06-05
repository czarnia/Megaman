#include "gameStateLobby.h"

gameStateLobby::gameStateLobby(SDL_Window *window, Renderer *renderer, Socket *skt):
    window(window),
    renderer(renderer),
    skt(skt)
{
    load();
}

void gameStateLobby::load(int stack){
    /// CARGO FONDO
    /// CARGO CARAS DE BOSSES
}

int gameStateLobby::unload(){

    return 0;
}

void gameStateLobby::updateInput(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            quit = true;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){


                default:
                    break;
            }
        }
    }
}

GameState::StateCode gameStateLobby::update(){
    updateInput();

    if (start){
       // start = false;
        return GameState::BOSS_SELECT;
    }else if (quit){
        return GameState::QUIT;
    }else{
        return GameState::CONTINUE;
    }
    return GameState::CONTINUE;
}

void gameStateLobby::render(){
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

gameStateLobby::~gameStateLobby(){
    unload();
}
