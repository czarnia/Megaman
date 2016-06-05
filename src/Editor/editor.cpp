#include "editor.h"
#include "../Cliente/gameState.h"
#include "gameStateEditor.h"


#define WIDTH 640
#define HEIGHT 480

Editor::Editor(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = new Window(WIDTH,HEIGHT);
    renderer = new Renderer(window->get_window());
}

void Editor::run(){

    GameState *currentState = NULL;
    currentState = new gameStateEditor(window, renderer);

    GameState::StateCode whatToDo;
    bool running = true;

    while (running){

        whatToDo = currentState->update();
        switch(whatToDo){
            case GameState::QUIT:
                running = false;
                break;
            default:
                break;
        }

        currentState->render();
    }

    delete currentState;
}


Editor::~Editor(){
    delete renderer;
    delete window;
    SDL_Quit();
}
