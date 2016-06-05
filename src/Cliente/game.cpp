#include "game.h"


#include "main_menu.h"
#include "gameStateStart.h"
#include "gameStateLobby.h"


#define FPS 60

#define WIDTH 640
#define HEIGHT 480
#define TAM_INT 4


Game::Game(char* hostname,char* port):
    skt(hostname,port),
    hostname(hostname),
    port(port)
{
    window = NULL;
    window = new Window(WIDTH,HEIGHT);
    renderer = NULL;
    renderer = new Renderer(window->get_window());
    currentState = new MainMenu(window, renderer);
}

void Game::run(){
    bool running = true;
    int namebytes = 4;
    while (running){
        GameState::StateCode whatToDo;
        whatToDo = currentState->update();
        switch (whatToDo){
            case GameState::MAIN_MENU:
                break;
            case GameState::BOSS_SELECT:
                delete currentState;
                renderer->clearSprites();

                skt.conect(hostname,port);
                ///////////////
                skt.send((char*)&namebytes, TAM_INT);
                skt.send("Axel", namebytes);
                ///////////////////////////
                currentState = new gameStateStart(window, renderer, &skt);
                std::cout<<"Entre al juego"<<std::endl;
               // currentState = new gameStateLobby(window, renderer, &skt);
                break;
            case GameState::GAME_START:



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

}

