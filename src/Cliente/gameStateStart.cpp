#include "gameStateStart.h"
#include <iostream>
#include <sstream>

#include "sender.h"
#include "background_sprite.h"
#include "block_sprite.h"
#include "character_sprite.h"
#include "response_handler.h"
#include "bar_sprite.h"
#include "event.h"

#define FPS 60
#define TAM_INT 4
#define MAPA 1
#define STATIC 1
#define NON_STATIC 0
#define FRONT 1
#define BACK 0
#define BACKGROUND 1

#define HP_BAR 6001
#define MP_BAR 6011
#define HP true
#define MP false

void gameStateStart::cap_framerate(const Uint32 &starting_tick){
    /// Aca limito los cuadros por segundo del juego para mantener
    /// una velocidad constante en distintas computadoras
    if ((1000/FPS) > SDL_GetTicks() - starting_tick){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - starting_tick));
    }
}

gameStateStart::gameStateStart(Window *window, Renderer *renderer, Socket *skt,
                                std::pair<int,std::string> &playerData,
                                int level):
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
    receiver = new Receiver(skt, renderer, &mutex);
    load(level);
}



void gameStateStart::load(int level){
    /// cargo el fondo del nivel
    std::ostringstream os;
    os << "../sprites/background"<<level<<".png";
    std::string mapBackground(os.str());
    Sprite *spr = new Sprite(renderer->get_renderer(), mapBackground.c_str());
    spr->setWidth(window->get_width());
    spr->setHeight(window->get_height());
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(BACKGROUND, spr, BACK, STATIC);
    /// Cargo musica del nivel
    std::ostringstream ms;
    ms <<"../Media/boss"<<level<<"_soundtrack.mp3";
    std::string musicpath(ms.str());
    music.changeTrack(musicpath.c_str());
    music.play();
    spr = new Sprite(renderer->get_renderer(), "cargando.png");
    spr->setWidth(100);
    spr->setHeight(70);
    spr->setPosX(window->get_width()/2-spr->getWidth()/2);
    spr->setPosY(window->get_height()/2-spr->getHeight()/2);
    renderer->addSprite(100, spr, FRONT, NON_STATIC);
    /// Recibo datos del mapa
    receiver->receiveMapSize();
    receiver->receiveMap(level);
    /// Vida y energia
    loadHUD();
    renderer->erase(100);
}

void gameStateStart::loadHUD(){
    Sprite *spr;
    /// VIDAS
    spr = new Bar_sprite(renderer->get_renderer(), HP);
    spr->setPosX(10);
    spr->setPosY(10);
    renderer->addSprite(HP_BAR, spr, FRONT, STATIC);

    spr = new Bar_sprite(renderer->get_renderer(), HP);
    spr->setPosX(120);
    spr->setPosY(10);
    renderer->addSprite(HP_BAR, spr, FRONT, STATIC);

    spr = new Bar_sprite(renderer->get_renderer(), HP);
    spr->setPosX(230);
    spr->setPosY(10);
    renderer->addSprite(HP_BAR, spr, FRONT, STATIC);

    spr = new Bar_sprite(renderer->get_renderer(), HP);
    spr->setPosX(340);
    spr->setPosY(10);
    renderer->addSprite(HP_BAR, spr, FRONT, STATIC);
    /// ENERGIA
    spr = new Bar_sprite(renderer->get_renderer(), MP);
    spr->setPosX(10);
    spr->setPosY(20);
    renderer->addSprite(MP_BAR, spr, FRONT, STATIC);

    spr = new Bar_sprite(renderer->get_renderer(), MP);
    spr->setPosX(120);
    spr->setPosY(20);
    renderer->addSprite(MP_BAR, spr, FRONT, STATIC);

    spr = new Bar_sprite(renderer->get_renderer(), MP);
    spr->setPosX(230);
    spr->setPosY(20);
    renderer->addSprite(MP_BAR, spr, FRONT, STATIC);

    spr = new Bar_sprite(renderer->get_renderer(), MP);
    spr->setPosX(340);
    spr->setPosY(20);
    renderer->addSprite(MP_BAR, spr, FRONT, STATIC);

}

int gameStateStart::unload(){
    music.stop();
    receiver->join();
    renderer->clearSprites();
    return 0;
}

void gameStateStart::updateInput(bool *running){
    /// Aca se procesa todo lo ingresado por teclado y se envia al servidor
    /// siguiendo el protocolo establecido
    static Sender sender(skt);
    SDL_Event event;
    static std::string direction = "right";
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            *running = false;
            quit = true;
            break;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_UP:
                    if(!up){
                        sender.send("move", "up"); // ENVIO LA TECLA
                        up = true;
                    }
                    break;
                case SDLK_DOWN:
                    if(!down){
                        sender.send("move", "down");  // ENVIO LA TECLA
                        down = true;
                    }
                    break;
                case SDLK_LEFT:
                    if(!left){
                      //  std::cout<<"se apreto izquierda"<<std::endl;
                        sender.send("move", "left");  // ENVIO LA TECLA
                        direction = "left";
                        left = true;
                    }
                    break;
                case SDLK_RIGHT:
                    if(!right){
                        sender.send("move", "right");  // ENVIO LA TECLA
                        direction = "right";
                        right = true;
                    }
                    break;
                case SDLK_s:
                    if(!jump){
                        sender.send("move","jump");
                        jump = true;
                    }
                    break;
                case SDLK_a:
                    if (!shoot){
                        sender.send("attack", direction);  // ENVIO LA TECLA
                        shoot = true;
                    }
                    break;
                case SDLK_1:
                    sender.send("gunChange","gun1");  // ENVIO LA TECLA
                    break;
                case SDLK_2:
                    sender.send("gunChange","gun2");  // ENVIO LA TECLA
                    break;
                case SDLK_3:
                    sender.send("gunChange","gun3");  // ENVIO LA TECLA
                    break;
                case SDLK_4:
                    sender.send("gunChange","gun4");  // ENVIO LA TECLA
                    break;
                case SDLK_5:
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
                case SDLK_a:
                    shoot = false;
                    break;
                default:
                    break;
            }
        }
    }

}

GameState::StateCode gameStateStart::update(){
    /// Main loop del juego
    /// aca adentro cambio los flags necesarios
    mainLoop();
    /// dependiendo del flag, le digo al juego que hacer a continuacion
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
    Event event;
    /// Realiza los cambios acordes a las respuestas del servidor
    ResponseHandler handler(renderer);
    /// Hilo receiver, recibe todo lo proveniente del servidor
    /// y lo almacena en una cola en forma de eventos
    receiver->start();
    bool running = true;
    /// Loop principal
    while (running){
        starting_tick = SDL_GetTicks();
        /// Recibo la entrada y envio al servidor
        /// Si se recibe un cierre de ventana, se corta la ejecucion

        updateInput(&running);
        /// Actualizo la posicion de camara
        if (renderer->find(playerData.first))
            renderer->updateCamPos(playerData.first);
        /// Verifico si la cola de eventos provenientes del servidor esta vacia

            while (!receiver->r_queue.empty()){
                /// Si hay algun evento, lo proceso
                std::pair<int,int> coord;

                mutex.lock();
                event = receiver->r_queue.front();
                receiver->r_queue.pop();
                mutex.unlock();

                coord.first = event.posX;
                coord.second = event.posY;

                /// acorde a lo recibido del servidor, seteo los flags correspondientes
                switch(handler.execute(event.command, event.objectType,
                        event.objectID, coord)){
                    case GameState::BOSS_SELECT:
                        running = false;
                        victory = true;
                        break;
                    case GameState::GAME_OVER:
                        running = false;
                        ko = true;
                        break;
                    default:
                        break;
                }
                //render();
            }


        /// dibujo
        mutex.lock();
        render();
        mutex.unlock();
        /// limito FPS

        cap_framerate(starting_tick);
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
