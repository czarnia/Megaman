#include "gameStateLobby.h"
#include "backround_sprite.h"
#include "boss_icon_sprite.h"
#include "selector_sprite.h"

#define BACKROUND 0
#define ICON 10
#define SELECTOR 100
#define TAM_INT 4

gameStateLobby::gameStateLobby(Window *window, Renderer *renderer,
                                Socket *skt, std::string &player):
    window(window),
    renderer(renderer),
    skt(skt),
    playername(player)
{
    window->setTitle("Megaman: Lobby");
    start = false;
    quit = false;
    playernumber = 1;
    selectorPos = 1;
    load();
}

void gameStateLobby::load(int stack){
    int namebytes = playername.size();
    skt->send((char*)&namebytes, TAM_INT);
    skt->send((char*)playername.c_str(), namebytes);
    /// ACA RECIBO MI NUMERO DE JUGADOR
    char buffer[TAM_INT];
    skt->receive(buffer, TAM_INT);
    playernumber = *((int*)buffer);
    /// POR AHORA
    playernumber = 1;

    Sprite *spr;
    /// CARGO FONDO
    spr = new Backround_sprite(renderer->get_renderer(), "../sprites/lobby_backround.jpeg");
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(BACKROUND, spr);
    /// CARGO CARAS DE BOSSES

    /// BOMBMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/bombman.png");
    spr->setPosX(1*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr);
    /// FIREMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/fireman.png");
    spr->setPosX(3*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr);
    /// MAGNETMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/magnetman.png");
    spr->setPosX(5*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr);
    /// RINGMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/ringman.png");
    spr->setPosX(7*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr);
    /// SPARKMAN
    spr = new Boss_icon_sprite(renderer->get_renderer(), "../sprites/sparkman.png");
    spr->setPosX(9*Boss_icon_sprite::width);
    spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
    renderer->addSprite(ICON, spr);
    /// CARGO SELECTOR
    if(playernumber == 1){
        spr = new Selector_sprite(renderer->get_renderer(), "../sprites/selector.png");
        spr->setPosX((selectorPos*2-1)*Boss_icon_sprite::width-5);
        spr->setPosY(window->get_height()/3-Boss_icon_sprite::height);
        renderer->addSprite(SELECTOR, spr);
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
                    moveSelector("right");
                    break;
                case SDLK_LEFT:
                    moveSelector("left");
                    break;
                case SDLK_RETURN:
                    start = true;
                    /// ACA ENVIO EL NUMERO DE BOSS
                    break;
                default:
                    break;
            }
        }
    }
}

void gameStateLobby::moveSelector(std::string direction){

    if (!direction.compare("right")){
        if (selectorPos < 5){
            selectorPos++;
            renderer->sprites[SELECTOR]->setPosX((selectorPos*2-1)*Boss_icon_sprite::width-5);
        }
    }else if (!direction.compare("left")){
        if (selectorPos > 1){
            selectorPos--;
            renderer->sprites[SELECTOR]->setPosX((selectorPos*2-1)*Boss_icon_sprite::width-5);
        }
    }
}

GameState::StateCode gameStateLobby::update(){
    /// SOLO EL JUGADOR 1 PUEDE ELEGIR BOSS
    if (playernumber == 1){
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
