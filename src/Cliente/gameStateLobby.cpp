#include "gameStateLobby.h"
#include "background_sprite.h"
#include "boss_icon_sprite.h"
#include "selector_sprite.h"

#include <iostream>

#define STATIC 1
#define NON_STATIC 0

#define BACKROUND 0
#define STARTING_SELECTION 5
#define ICON 10
#define BUTTON 5
#define SELECTOR 100
#define TAM_INT 4


gameStateLobby::gameStateLobby(Window *window, Renderer *renderer,
                                Socket *skt, std::pair<int, std::string> &playerData):
    window(window),
    renderer(renderer),
    skt(skt),
    playerData(playerData)
{
    window->setTitle("Megaman: Lobby");
    start = false;
    quit = false;
    startSelect = false;
    playerData.first = 1;
    selectorPos = 1;
    load();
}

void gameStateLobby::load(int stack){
    /// MANDO EL NOMBRE QUE SE INGRESO
    int namebytes = playerData.second.size();
    if(namebytes == 0)
        playerData.second = "unnamed";
    namebytes = playerData.second.size();
    skt->send((char*)&namebytes, TAM_INT);
    skt->send((char*)playerData.second.c_str(), namebytes);
    /// ACA RECIBO MI NUMERO DE JUGADOR
    char buffer[TAM_INT];
    skt->receive(buffer, TAM_INT);
    playerData.first = *((int*)buffer);
    /// POR AHORA
    playerData.first = 1;

    Sprite *spr;
    /// CARGO FONDO
    spr = new Background_sprite(renderer->get_renderer(), "../sprites/lobby_background.jpeg");
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(BACKROUND, spr, 0, STATIC);
    /// CARGO CARAS DE BOSSES

    /// BOMBMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/bombman.png");
    spr->setPosX(1*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, 0, STATIC);
    /// FIREMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/fireman.png");
    spr->setPosX(3*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, 0, STATIC);
    /// MAGNETMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/magnetman.png");
    spr->setPosX(5*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, 0, STATIC);
    /// RINGMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/ringman.png");
    spr->setPosX(7*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, 0, STATIC);
    /// SPARKMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/sparkman.png");
    spr->setPosX(9*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, 0, STATIC);

    if(playerData.first == 1){
        /// CARGO SELECTOR
        spr = new Selector_sprite(renderer->get_renderer(), "../sprites/selector.png");
        spr->setPosX((selectorPos*2-1)*Boss_icon_sprite::width-5);
        spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
        renderer->addSprite(SELECTOR, spr, 0, STATIC);
        /// BOTON START
        spr = new Sprite(renderer->get_renderer(), "../sprites/start_button.png");
        spr->setWidth(100);
        spr->setHeight(100);
        spr->setPosX(window->get_width()/2 - spr->getWidth()/2);
        spr->setPosY(window->get_height()*3/5);
        renderer->addSprite(BUTTON, spr, 0, STATIC);
    }
}

int gameStateLobby::unload(){
    renderer->clearSprites();
    return 0;
}

void gameStateLobby::updateInput(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            quit = true;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_RIGHT:
                    if(startSelect)
                        moveSelector("right");
                    break;
                case SDLK_LEFT:
                    if(startSelect)
                        moveSelector("left");
                    break;
                case SDLK_RETURN:
                    if(startSelect)
                        start = true;
                    /// ACA ENVIO EL NUMERO DE BOSS
                    break;
                default:
                    break;
            }
        }else if (event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT){
                int Xpressed = event.button.x;
                int Ypressed = event.button.y;
                if(buttonPress(Xpressed,Ypressed,(renderer->static_sprites[0])[BUTTON])){
                    int command = STARTING_SELECTION;

                    if(!startSelect){
                      //  skt->send((char*)&command, TAM_INT);
                        startSelect = true;
                    }
                }
            }
        }
    }
}

bool gameStateLobby::buttonPress(int x, int y, Sprite *spr){
    if (x > spr->getPosX() && x < spr->getPosX()+spr->getWidth())
        if (y > spr->getPosY() && y < spr->getPosY()+spr->getHeight())
            return true;
    return false;
}

void gameStateLobby::moveSelector(std::string direction){

    if (!direction.compare("right")){
        if (selectorPos < 5){
            selectorPos++;
            renderer->static_sprites[0][SELECTOR]->setPosX((selectorPos*2-1)*Boss_icon_sprite::width-5);
        }
    }else if (!direction.compare("left")){
        if (selectorPos > 1){
            selectorPos--;
            renderer->static_sprites[0][SELECTOR]->setPosX((selectorPos*2-1)*Boss_icon_sprite::width-5);
        }
    }
}

GameState::StateCode gameStateLobby::update(){
    /// SOLO EL JUGADOR 1 PUEDE ELEGIR BOSS
    if (playerData.first == 1){
        updateInput();
    }else{
        char buffer[TAM_INT];
        int command;
        skt->receive(buffer, TAM_INT);
        command = *((int*)buffer);
        if(command == 1)
            start = true;
    }

    if (start){
        return GameState::GAME_START;
    }else if (quit){
        return GameState::QUIT;
    }else{
        return GameState::CONTINUE;
    }
    return GameState::CONTINUE;
}

void gameStateLobby::render(){
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

gameStateLobby::~gameStateLobby(){
    unload();
}
