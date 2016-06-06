#include "game.h"

#include "main_menu.h"
#include "gameStateStart.h"
#include "gameStateLobby.h"

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
    window = NULL;
    window = new Window(WIDTH,HEIGHT);
    renderer = NULL;
    renderer = new Renderer(window);
    currentState = new MainMenu(window, renderer, playername);
}

void Game::run(){
    bool running = true;
    while (running){
        GameState::StateCode whatToDo;
        whatToDo = currentState->update();
        switch (whatToDo){
            case GameState::MAIN_MENU:
                break;
            case GameState::BOSS_SELECT:

                delete currentState;
                skt.conect(hostname,port);
                currentState = new gameStateLobby(window, renderer, &skt, playername);

                break;
            case GameState::GAME_START:
                delete currentState;
                ///////////////

                ///////////////////////////
                currentState = new gameStateStart(window, renderer, &skt);
                std::cout<<"Entre al juego"<<std::endl;
                break;
            case GameState::GAME_OVER:
                break;
            case GameState::VICTORY:
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

