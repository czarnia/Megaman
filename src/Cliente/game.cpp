#include "game.h"
#include "Renderer.h"
#include "Sprite.h"
#include "main_menu.h"
#include "gameStateStart.h"
#include "../Comun/mutex.h"
#include <vector>
#include <exception>

#define FPS 60
#define ORIGIN_CENTERED 1
#define ORIGIN_CORNER 0
#define FONDO 1
#define FONDO_HP 2
#define WIDTH 640
#define HEIGHT 480


Game::Game(char* hostname,char* port):
    skt(hostname,port),
    hostname(hostname),
    port(port){
    window = NULL;
    window = SDL_CreateWindow("Main menu",
                                SDL_WINDOWPOS_UNDEFINED, // POS X
                                SDL_WINDOWPOS_UNDEFINED, // POS Y
                                WIDTH,
                                HEIGHT,
                                SDL_WINDOW_SHOWN);
    renderer = NULL;
    renderer = new Renderer(window);
    currentState = new MainMenu(window, renderer);


}

void Game::cap_framerate(const Uint32 &starting_tick){
    if ((1000/FPS) > SDL_GetTicks() - starting_tick){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - starting_tick));
    }
}

void Game::run(){
    bool running = true;
    while (running){
        GameState::StateCode whatToDo;
                        std::cout<<"TODO OK"<<std::endl;
        whatToDo = currentState->update();
        switch (whatToDo){
            case GameState::MAIN_MENU:
                break;
            case GameState::BOSS_SELECT:
                delete currentState;

                skt.conect(hostname,port);
                currentState = new gameStateStart(window,renderer, &skt);
                std::cout<<"Entre al juego"<<std::endl;
                break;
            case GameState::GAME_START:

                break;
            case GameState::GAME_OVER:
                break;
            case GameState::VICTORY:
                break;
            case GameState::CONTINUE:
                std::cout<<"Continuo"<<std::endl;
                break;
            case GameState::QUIT:
                running = false;
                break;
            default:
                break;
		}
        renderer->clear();
        renderer->drawAll();
        renderer->present();
    }

}



Game::~Game(){
    SDL_DestroyWindow(window);
    delete renderer;
    window = NULL;

}

