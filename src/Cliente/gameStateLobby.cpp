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

GameState::StateCode gameStateLobby::update(){

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
