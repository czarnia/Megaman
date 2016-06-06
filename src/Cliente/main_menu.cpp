#include "main_menu.h"
#include "gameState.h"
#include "backround_sprite.h"

#define BACKROUND 0

#include <iostream>

MainMenu::MainMenu(Window *window, Renderer *renderer, std::string &player):
    window(window),
    renderer(renderer),
    playerName(player)
{
    window->setTitle("Megaman: Main menu");
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
                case SDLK_n:{
                    SDL_StartTextInput();
                    if(event.type == SDL_TEXTINPUT)
                        playerName += event.text.text;
                    SDL_StopTextInput();
                    std::cout << playerName <<std::endl;
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void MainMenu::load(int stack){
    /// FONDO
    Sprite *spr = new Backround_sprite(renderer->get_renderer(), "../sprites/menu_backround.jpeg");
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(BACKROUND,spr);
}

int MainMenu::unload(){
    renderer->clearSprites();
    return 0;
}

GameState::StateCode MainMenu::update(){
    updateInput();

    if (start){
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
