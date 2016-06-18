#include "main_menu.h"
#include "background_sprite.h"
#include "text_sprite.h"
#include <SDL2/SDL_ttf.h>

#define STATIC 1
#define NON_STATIC 0
#define FRONT 1
#define BACK 0

#define BACKGROUND 0
#define TEXT 100

#include <iostream>

MainMenu::MainMenu(Window *window, Renderer *renderer,
                    std::pair<int, std::string> &playerData):
    window(window),
    renderer(renderer),
    playerData(playerData)
{
    window->setTitle("Megaman: Main menu");
    start = false;
    quit = false;
    load();
}

void MainMenu::load(int stack){
    /// Cargo todos los sprites del menu principal
    /// FONDO
    Sprite *spr = new Background_sprite(renderer->get_renderer(), "../sprites/menu_background2.png");
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(BACKGROUND, spr, BACK, STATIC);
    /// ETCs
    spr = new Sprite(renderer->get_renderer(), "../sprites/nickname_sign.png");
    spr->setWidth(80);
    spr->setHeight(60);
    spr->setPosX(window->get_width()/2 -spr->getWidth()-5);
    spr->setPosY(window->get_height()*1/9);
    renderer->addSprite(BACKGROUND, spr, BACK, STATIC);

    spr = new Sprite(renderer->get_renderer(), "../sprites/menu_megaman.png");
    spr->setWidth(80);
    spr->setHeight(120);
    spr->setPosX(window->get_width()-spr->getWidth());
    spr->setPosY(window->get_height()/2-spr->getHeight()/2);
    renderer->addSprite(BACKGROUND, spr, BACK, STATIC);

    spr = new Sprite(renderer->get_renderer(), "../sprites/mensaje.png");
    spr->setWidth(400);
    spr->setHeight(50);
    spr->setPosX(window->get_width()/2 - spr->getWidth()/2);
    spr->setPosY(window->get_height()*3/4);
    renderer->addSprite(BACKGROUND, spr, BACK, STATIC);

    music.changeTrack("../Media/menu_soundtrack.mp3");
    music.play();
}

int MainMenu::unload(){
    /// Libero los sprites cargados
    music.stop();
    renderer->clearSprites();
    return 0;
}

GameState::StateCode MainMenu::update(){
    /// Proceso la entrada por teclado
    /// desde aca adentro modifico los flags necesarios
    updateInput();

    /// Si se modifico algun flag, hago lo necesario
    if (start){
        return GameState::BOSS_SELECT;
    }else if (quit){
        return GameState::QUIT;
    }else{
        return GameState::CONTINUE;
    }

}

void MainMenu::updateInput(){
    /// Permito el ingreso de texto, y espero un ENTER para comenzar
    SDL_Event event;
    SDL_StartTextInput();
    while (SDL_PollEvent(&event)){

        if (event.type == SDL_QUIT){
            quit = true;

        }else if (event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym == SDLK_RETURN)
                start = true;
            if (event.key.keysym.sym == SDLK_BACKSPACE && playerData.second.size() > 0){
                playerData.second.erase(playerData.second.size()-1);
                Sprite *spr = new Text_sprite(renderer->get_renderer(), playerData.second, 25);
                spr->setPosX(window->get_width()/2);
                spr->setPosY(window->get_height()*1/9+10);
                renderer->erase(TEXT);
                renderer->addSprite(TEXT, spr, FRONT, NON_STATIC);
            }
        }else if (event.type == SDL_TEXTINPUT){
            playerData.second.append(event.text.text);

            Sprite *spr = new Text_sprite(renderer->get_renderer(), playerData.second, 25);
            spr->setPosX(window->get_width()/2);
            spr->setPosY(window->get_height()*1/9+10);
            renderer->erase(TEXT);
            renderer->addSprite(TEXT, spr, FRONT, NON_STATIC);
        }
    }
    SDL_StopTextInput();
}

void MainMenu::render(){
    /// Limpia la pantalla, dibuja y presenta los sprites cargados
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

MainMenu::~MainMenu(){
    unload();
}
