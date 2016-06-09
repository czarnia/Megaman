#include "game.h"

#include "main_menu.h"
#include "gameStateStart.h"
#include "gameStateLobby.h"
#include <SDL2/SDL_ttf.h>

#define FPS 60
#define WIDTH 640
#define HEIGHT 480



Game::Game(char* hostname,char* port):
    skt(hostname,port),
    hostname(hostname),
    port(port)
{
	SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    window = new Window(WIDTH,HEIGHT);
    renderer = new Renderer(window);
    currentState = new MainMenu(window, renderer, playerData);
    level = 0;
}

void Game::run(){
    bool running = true;
    skt.conect(hostname,port);
    while (running){
        GameState::StateCode whatToDo;
        whatToDo = currentState->update();
        switch (whatToDo){
            case GameState::MAIN_MENU:
                break;
            case GameState::BOSS_SELECT:

                delete currentState;
                currentState = new gameStateLobby(window, renderer, &skt, playerData, &level);

                break;
            case GameState::GAME_START:

                delete currentState;
                currentState = new gameStateStart(window, renderer, &skt, playerData, level);
                std::cout<<"Entre al juego"<<std::endl;

                break;
            case GameState::GAME_OVER:

                delete currentState;
                currentState = new MainMenu(window, renderer, playerData);

                break;
            case GameState::VICTORY:

                delete currentState;
                currentState = new gameStateLobby(window, renderer, &skt, playerData, &level);

                break;
            case GameState::CONTINUE:
                break;
            case GameState::QUIT:
                running = false;
                break;
            default:
                break;
		}
		currentState->render();
    }
    skt.shutdown(SHUT_RDWR);
}

Game::~Game(){
    delete window;
    delete renderer;
    window = NULL;
    TTF_Quit();
    SDL_Quit();
}

