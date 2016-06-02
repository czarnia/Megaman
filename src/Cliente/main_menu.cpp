#include "main_menu.h"
#include "gameState.h"
#include "backround_sprite.h"
#define BACKROUND 0

MainMenu::MainMenu(SDL_Window *window, Renderer *renderer):
    window(window),
    renderer(renderer)
{
    start = false;
    quit = false;
    load();
}

void MainMenu::updateInput(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            quit = true;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_RETURN:
                    start = true;
                    break;
                default:
                    break;
            }
        }
    }
}

void MainMenu::load(int stack){
    Sprite *spr = new Backround_sprite(renderer->get_renderer(), "sprites/menu_backround.jpeg");
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(BACKROUND,spr);
}

int MainMenu::unload(){

    return 0;
}

GameState::StateCode MainMenu::update(){
    updateInput();

    if (start){
       // start = false;
        return GameState::BOSS_SELECT;
    }else if (quit){
        return GameState::QUIT;
    }else{
        return GameState::CONTINUE;
    }
}

void MainMenu::render(){
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

MainMenu::~MainMenu(){
    unload();
}
