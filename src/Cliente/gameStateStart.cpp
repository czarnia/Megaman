#include "gameStateStart.h"
#include <iostream>
#include "sender.h"
#include "block_sprite.h"

#define FPS 60
#define TAM_INT 4

gameStateStart::gameStateStart(Window *window, Renderer *renderer, Socket *skt,
                                std::pair<int,std::string> &playerData):
    playerData(playerData),
    window(window),
    renderer(renderer),
    skt(skt),
    up(false),
    down(false),
    left(false),
    right(false),
    jump(false),
    quit(false),
    victory(false),
    ko(false)
{
    window->setTitle("Megaman: Playing");
    window->maximize();
    receiver = new Receiver(skt, renderer, &victory, &ko);
    load();
}

void gameStateStart::cap_framerate(const Uint32 &starting_tick){
    if ((1000/FPS) > SDL_GetTicks() - starting_tick){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - starting_tick));
    }
}

void gameStateStart::load(int stack){
    /// Recibo el mapa
    receiver->receiveMapSize();
    receiver->receiveMap();
}

int gameStateStart::unload(){

    return 0;
}

void gameStateStart::updateInput(bool *running){
    static Sender sender(skt);
    SDL_Event event;
    std::string direction;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            *running = false;
            quit = true;
            break;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_UP:
                    if(!up){
                        std::cout<<"se apreto arriba"<<std::endl;
                        sender.send("move", "up"); // ENVIO LA TECLA
                        up = true;
                    }
                    break;
                case SDLK_DOWN:
                    if(!down){
                        std::cout<<"se apreto abajo"<<std::endl;
                        sender.send("move", "down");  // ENVIO LA TECLA
                        down = true;
                    }
                    break;
                case SDLK_LEFT:
                    if(!left){
                        std::cout<<"se apreto izquierda"<<std::endl;
                        sender.send("move", "left");  // ENVIO LA TECLA
                        direction = "left";
                        left = true;
                    }
                    break;
                case SDLK_RIGHT:
                    if(!right){
                        std::cout<<"se apreto derecha"<<std::endl;
                        sender.send("move", "right");  // ENVIO LA TECLA
                        direction = "right";
                        right = true;
                    }
                    break;
                case SDLK_s:
                    if(!jump){
                        std::cout<<"Se salto"<<std::endl;
                        sender.send("move","jump");
                        jump = true;
                    }
                    break;
                case SDLK_a:
                    std::cout<<"Se disparo"<<std::endl;
                    sender.send("attack", direction);  // ENVIO LA TECLA
                    break;
                case SDLK_1:
                    std::cout<<"Se cambio de arma 1"<<std::endl;
                    sender.send("gunChange","gun1");  // ENVIO LA TECLA
                    break;
                case SDLK_2:
                    std::cout<<"Se cambio de arma 2"<<std::endl;
                    sender.send("gunChange","gun2");  // ENVIO LA TECLA
                    break;
                case SDLK_3:
                    std::cout<<"Se cambio de arma 3"<<std::endl;
                    sender.send("gunChange","gun3");  // ENVIO LA TECLA
                    break;
                case SDLK_4:
                    std::cout<<"Se cambio de arma 4"<<std::endl;
                    sender.send("gunChange","gun4");  // ENVIO LA TECLA
                    break;
                case SDLK_5:
                    std::cout<<"Se cambio de arma 5"<<std::endl;
                    sender.send("gunChange","gun5");  // ENVIO LA TECLA
                    break;
                default:
                    break;
            }
        }else if (event.type == SDL_KEYUP){
            switch (event.key.keysym.sym){
                case SDLK_UP:
                    sender.send("stop", "up"); // ENVIO LA TECLA
                    up = false;
                    break;
                case SDLK_DOWN:
                    sender.send("stop", "down");  // ENVIO LA TECLA
                    down = false;
                    break;
                case SDLK_LEFT:
                    sender.send("stop", "left");  // ENVIO LA TECLA
                    left = false;
                    break;
                case SDLK_RIGHT:
                    sender.send("stop", "right");  // ENVIO LA TECLA
                    right = false;
                    break;
                case SDLK_s:
                    sender.send("stop","jump");
                    jump = false;
                    break;
                default:
                    break;
            }
        }
    }
}

GameState::StateCode gameStateStart::update(){
    mainLoop();
    if (quit)
        return GameState::QUIT;
    else if(victory)
        return GameState::BOSS_SELECT;
    else if(ko)
        return GameState::GAME_OVER;
    else
        return GameState::CONTINUE;
}

void gameStateStart::mainLoop(){
    Uint32 starting_tick;
    bool running = true;

    while (running){
        starting_tick = SDL_GetTicks();
        /// COMUNICACION
        updateInput(&running);
        std::cout << playerData.first<<std::endl;
        if (renderer->find(playerData.first))
            renderer->updateCamPos(playerData.first);
        receiver->update(&running);
        ///
		cap_framerate(starting_tick);
        render();
	}
}

void gameStateStart::render(){
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

gameStateStart::~gameStateStart(){
    unload();
    delete receiver;
}
