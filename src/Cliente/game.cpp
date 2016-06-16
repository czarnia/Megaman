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

    /// LOOP PRINCIPAL DEL CLIENTE
    while (running){
        /// Estado
        GameState::StateCode whatToDo;
        /// Aca se lleva a cabo toda la logica interna de cada estado
        /// dependiendo de lo que devuelva el update se realizara un cambio
        /// de estado  o se cerrara el juego
        /// Notar que update es una funcion polimorfica, por lo que dependiendo
        /// del estado actual, se realizaran distintas tareas al llamarla
        whatToDo = currentState->update();
        /// Al crear cada estado, se cargan todos los recursos necesarios para
        /// ejecutarlo
        switch (whatToDo){
            /// Menu principal
            case GameState::MAIN_MENU:
                currentState = new MainMenu(window, renderer, playerData);
                break;
            /// Boss select, ni bien entro aca, me conecto al servidor
            case GameState::BOSS_SELECT:
                skt.conect(hostname,port);
                if(currentState)
                    delete currentState;
                currentState = new gameStateLobby(window, renderer, &skt, playerData, &level);
                break;
            /// El juego en si, este estado presenta un loop infinito propio
            case GameState::GAME_START:
                delete currentState;
                currentState = new gameStateStart(window, renderer, &skt, playerData, level);
                std::cout<<"Entre al juego"<<std::endl;
                break;
            /// Game over, se regresa al menu principal
            case GameState::GAME_OVER:
                delete currentState;
                currentState = NULL;
                whatToDo = GameState::MAIN_MENU;
                break;
            /// Victory, se regresa al lobby
            case GameState::VICTORY:
                delete currentState;
                currentState = NULL;
                whatToDo = GameState::BOSS_SELECT;
                break;
            /// Continua en el estado actual
            case GameState::CONTINUE:
                break;
            /// Sale del cliente
            case GameState::QUIT:
                running = false;
                break;
            default:
                break;
		}
		/// Despues de cada iteracion presento lo que se haya cargado al renderer
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

