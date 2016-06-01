#include "gameStateStart.h"
#include <iostream>
#include "sender.h"

#define FPS 60

gameStateStart::gameStateStart(SDL_Window *window, Renderer *renderer, Socket *skt):
    window(window),
    renderer(renderer),
    skt(skt),
    quit(false),
    victory(false),
    ko(false)
{
}

void gameStateStart::cap_framerate(const Uint32 &starting_tick){
    if ((1000/FPS) > SDL_GetTicks() - starting_tick){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - starting_tick));
    }
}

void gameStateStart::load(int stack){

}

int gameStateStart::unload(){

    return 0;
}

void gameStateStart::updateInput(bool *running){
    Sender sender(skt);
    SDL_Event event;
    std::string direction;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            *running = false;
            quit = true;
            break;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_UP:
                    std::cout<<"se apreto arriba"<<std::endl;
                    sender.send("move", "up"); // ENVIO LA TECLA
                    break;
                case SDLK_DOWN:
                    std::cout<<"se apreto abajo"<<std::endl;
                    sender.send("move", "down");  // ENVIO LA TECLA
                    break;
                case SDLK_LEFT:
                    std::cout<<"se apreto izquierda"<<std::endl;
                    sender.send("move", "left");  // ENVIO LA TECLA
                    direction = "left";
                    break;
                case SDLK_RIGHT:
                    std::cout<<"se apreto derecha"<<std::endl;
                    sender.send("move", "right");  // ENVIO LA TECLA
                    direction = "right";
                    break;
                case SDLK_s:
                    std::cout<<"Se salto"<<std::endl;
                    sender.send("move","jump");
                    break;
                case SDLK_a:
                    std::cout<<"Se disparo"<<std::endl;
                    sender.send("attack",direction);  // ENVIO LA TECLA
                    break;
                case SDLK_1:
                    std::cout<<"Se cambio de arma 1"<<std::endl;
                    sender.send("gunChange","gun1");  // ENVIO LA TECLA
                    break;
                case SDLK_2:
                    std::cout<<"Se cambio de arma 2"<<std::endl;
                    sender.send("gunChange","gun2");  // ENVIO LA TECLA
                    break;
                case SDLK_3:
                    std::cout<<"Se cambio de arma 3"<<std::endl;
                    sender.send("gunChange","gun3");  // ENVIO LA TECLA
                    break;
                case SDLK_4:
                    std::cout<<"Se cambio de arma 4"<<std::endl;
                    sender.send("gunChange","gun4");  // ENVIO LA TECLA
                    break;
                case SDLK_5:
                    std::cout<<"Se cambio de arma 5"<<std::endl;
                    sender.send("gunChange","gun5");  // ENVIO LA TECLA
                    break;
                default:
                    break;
            }
        }
    }
}

GameState::StateCode gameStateStart::update(){
    mainLoop();
    if (quit)
        return GameState::QUIT;
    else if(victory)
        return GameState::VICTORY;
    else if(ko)
        return GameState::GAME_OVER;
}

void gameStateStart::mainLoop(){
    Uint32 starting_tick;
    bool running = true;

    while (running){
        starting_tick = SDL_GetTicks();
        updateInput(&running);

		cap_framerate(starting_tick);
        renderer->clear();
        renderer->drawAll();
        renderer->present();
	}
}

gameStateStart::~gameStateStart(){

}
