#include "response_handler.h"
#include <iostream>
#include "character_sprite.h"
#include "gameState.h"

#define MAPA 1
#define BARRA_VIDA 2
#define BARRA_ENERGIA 3
#define VIDAS 4
#define VICTORIA 5
#define GAMEOVER 6
#define MEGAMAN 1

ResponseHandler::ResponseHandler(Renderer &renderer, Mutex &mutex):
    renderer(renderer),
    mutex(mutex)
{
}

int ResponseHandler::execute(int command, int option, std::pair<int,int> coord){
    Sprite *spr = NULL;
    switch (command){
            case MAPA:
                std::cout<<"Recibi nueva posicion para: "<<option<<"y es";
                std::cout<<coord.first<<","<<coord.second<<std::endl;
                spr = new Main_character(renderer.get_renderer(),"megaman.jpeg");
                spr->setPosX(coord.first);
                spr->setPosY(coord.second);
                mutex.lock();
                renderer.addSprite(MEGAMAN, spr);
                mutex.unlock();
                break;
            case BARRA_VIDA:
                std::cout<<"Recibi nivel de vida: "<<option<<std::endl;

                break;
            case BARRA_ENERGIA:
                std::cout<<"Recibi nivel de energia: "<<option<<std::endl;

                break;
            case VIDAS:
                std::cout<<"Recibi vidas: "<<option<<std::endl;

                break;
            case VICTORIA:{
                std::cout<<"Recibi victoria: "<<std::endl;
                return GameState::BOSS_SELECT;
                break;
            }
            case GAMEOVER:{
                std::cout<<"Recibi gameover: "<<std::endl;
                return GameState::GAME_OVER;
                break;
            }
            default:
                return GameState::CONTINUE;
                break;
        }
    return GameState::CONTINUE;
}

ResponseHandler::~ResponseHandler(){
}

