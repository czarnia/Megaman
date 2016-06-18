#include "gameStateLobby.h"
#include "background_sprite.h"
#include "boss_icon_sprite.h"
#include "selector_sprite.h"
#include "lobbyreceiver.h"

#include <iostream>

#define STATIC 1
#define NON_STATIC 0
#define FRONT 1
#define BACK 0

#define BACKROUND 0
#define STARTING_SELECTION 5
#define ICON 10
#define BUTTON 5
#define SELECTOR 100
#define TAM_INT 4

#define START_GAME 0
#define BOSS_CHOSEN 6

gameStateLobby::gameStateLobby(Window *window, Renderer *renderer,
                                Socket *skt, std::pair<int,
                                 std::string> &playerData, int *level):
    window(window),
    renderer(renderer),
    skt(skt),
    playerData(playerData),
    level(level)
{
    window->setTitle("Megaman: Lobby");
    start = false;
    quit = false;
    running = true;
    startSelect = false;
    selectorPos = 1;
    receiver = new LobbyReceiver(skt, renderer, &mutex);
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

    /// Cargo los sprites de este menu
    Sprite *spr;
    /// CARGO FONDO
    spr = new Background_sprite(renderer->get_renderer(), "../sprites/lobby_background.jpeg");
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(BACKROUND, spr, BACK, STATIC);
    /// CARGO CARAS DE BOSSES

    /// BOMBMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/bombman_icon.png");
    spr->setPosX(1*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, BACK, STATIC);
    /// FIREMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/fireman_icon.png");
    spr->setPosX(3*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, BACK, STATIC);
    /// MAGNETMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/magnetman_icon.png");
    spr->setPosX(5*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, BACK, STATIC);
    /// RINGMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/ringman_icon.png");
    spr->setPosX(7*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, BACK, STATIC);
    /// SPARKMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/sparkman.png");
    spr->setPosX(9*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr, BACK, STATIC);

    /// Solo el jugador 1 puede presionar el boton y elegir boss
    if(playerData.first == 1){
        /// CARGO SELECTOR
        spr = new Selector_sprite(renderer->get_renderer(), "../sprites/selector.png");
        spr->setPosX((selectorPos*2-1)*Boss_icon_sprite::width-5);
        spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
        renderer->addSprite(SELECTOR, spr, BACK, STATIC);
        /// BOTON START
        spr = new Sprite(renderer->get_renderer(), "../sprites/start_button.png");
        spr->setWidth(100);
        spr->setHeight(50);
        spr->setPosX(window->get_width()/2 - spr->getWidth()/2);
        spr->setPosY(window->get_height()*3/5);
        renderer->addSprite(BUTTON, spr, FRONT, STATIC);
    }else{
        /// CARGO CARTEL DE ESPERA
        spr = new Sprite(renderer->get_renderer(), "../sprites/lobbysign.png");
        spr->setWidth(400);
        spr->setHeight(75);
        spr->setPosX(window->get_width()/2 - spr->getWidth()/2);
        spr->setPosY(window->get_height()*3/5);
        renderer->addSprite(BUTTON, spr, FRONT, STATIC);
    }
    music.changeTrack("../Media/lobby_soundtrack.mp3");
    music.play();
}

int gameStateLobby::unload(){
    music.stop();
    renderer->clearSprites();
    return 0;
}

GameState::StateCode gameStateLobby::update(){

    /// ACA LANZO UN HILO PARA ESPERAR QUE EL SERVIDOR
    /// ME INDIQUE EL COMIENZO DE PARTIDA Y NUMERO DE BOSS
    receiver->start();
    if (playerData.first == 1){
        while (running){
            /// SOLO EL JUGADOR 1 PUEDE ELEGIR BOSS
            updateInput();
            render();
        }
    }

    /// ESPERO A RECIBIR UNA SEñAL PARA EMPEZAR
    int starting = 1;
    while (starting != 0){
        if (!receiver->r_queue.empty()){
            /// START
            mutex.lock();
            starting = receiver->r_queue.front();
            receiver->r_queue.pop();
            SDL_Delay(10);
            if (starting == START_GAME)
                std::cout<<"Se esta por empezar un nivel"<<std::endl;
            /// BOSS
            *level = receiver->r_queue.front();
            receiver->r_queue.pop();
            mutex.unlock();
            start = true;
        }
        render();
    }
    receiver->join();
    ///
    if (start){

        return GameState::GAME_START;
    }else if (quit){

        return GameState::QUIT;
    }else{
        return GameState::CONTINUE;
    }
    return GameState::CONTINUE;
}

void gameStateLobby::updateInput(){
    /// Aca se ingresa solo si es el jugador 1
    /// esto permite el movimiento del selector y el comienzo de la partida
    /// los datos sobre el boss elegido se mandan inmediatamente despues
    /// de elegido el boss
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
                    if(startSelect){
                        /// Envio el numero de boss elegido
                        start = true;
                        running = false;
                        int command = BOSS_CHOSEN;
                        skt->send((char*)&command, TAM_INT);
                        int bossNumber = selectorPos;
                        skt->send((char*)&bossNumber, TAM_INT);
                    }
                    break;
                default:
                    break;
            }
        }else if (event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT){
                int Xpressed = event.button.x;
                int Ypressed = event.button.y;
                if(buttonPress(Xpressed,Ypressed,(renderer->static_sprites[FRONT])[BUTTON])){
                    int command = STARTING_SELECTION;
                    if(!startSelect){
                        /// Mando que voy a empezar a elegir boss
                        command = 5;
                        skt->send((char*)&command, TAM_INT);
                        command = 0;
                        /// mando algo vacio
                        skt->send((char*)&command, TAM_INT);
                        startSelect = true;
                        /// Imprimo un cartel informativo
                        Sprite *spr = new Sprite(renderer->get_renderer(), "../sprites/lobbymessage.png");
                        spr->setWidth(450);
                        spr->setHeight(100);
                        spr->setPosX(window->get_width()/2 - spr->getWidth()/2);
                        spr->setPosY(window->get_height()*3/5+60);
                        renderer->addSprite(500, spr, FRONT, STATIC);
                    }
                }
            }
        }
    }
}

bool gameStateLobby::buttonPress(int x, int y, Sprite *spr){
    /// Verifico si se apreto el boton
    if (x > spr->getPosX() && x < spr->getPosX()+spr->getWidth())
        if (y > spr->getPosY() && y < spr->getPosY()+spr->getHeight())
            return true;
    return false;
}

void gameStateLobby::moveSelector(std::string direction){
    /// El nombre es bastante descriptivo
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

void gameStateLobby::render(){
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

gameStateLobby::~gameStateLobby(){
    unload();
}
