#include "response_handler.h"
#include <iostream>
#include "character_sprite.h"
#include "minion_sprite.h"
#include "bullet_sprite.h"
#include "gameState.h"

#define END_OF_RESPONSE 6666
#define MAPA 1
#define BARRA_VIDA 2
#define BARRA_ENERGIA 3
#define VIDAS 4
#define VICTORIA 5
#define GAMEOVER 6
#define MEGAMAN 1
#define BULLET 2
#define MET 8

ResponseHandler::ResponseHandler(Renderer *renderer):
    renderer(renderer)
{
}

int ResponseHandler::execute(int command, int objectType, int objectID, std::pair<int,int> coord){
    Sprite *spr = NULL;
    switch (command){
            case MAPA:
                std::cout<<"Recibi nueva posicion para: "<<objectType
                <<"nro:"<<objectID<<"y es";
                std::cout<<coord.first<<","<<coord.second<<std::endl;
                /// SI recibi coordenadas negativas destruyo el objeto
                if(coord.first < 0){
                    renderer->erase(objectType+objectID);
                /// SI ya existe le cambio la posicion
                }else if(renderer->find(objectType+objectID)){
                    renderer->sprites[objectType+objectID]->setPosX(coord.first);
                    renderer->sprites[objectType+objectID]->setPosY(coord.second);
                /// Si no existe lo creo y le seteo la posicion
                }else{
                    switch(objectType){
                        case MEGAMAN:
                            spr = new Main_character(renderer->get_renderer(),"../sprites/megaman.png");
                            spr->setPosX(coord.first);
                            spr->setPosY(coord.second);
                            renderer->addSprite(objectType+objectID, spr);
                            break;
                        case MET:
                            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/met.png");
                            spr->setPosX(coord.first);
                            spr->setPosY(coord.second);
                            renderer->addSprite(objectType+objectID, spr);
                        case BULLET:
                            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/bullet.png");
                            spr->setPosX(coord.first);
                            spr->setPosY(coord.second);
                            renderer->addSprite(objectType+objectID, spr);
                    }
                }
                break;
            case BARRA_VIDA:
                std::cout<<"Recibi nivel de vida: "<<objectType<<std::endl;

                break;
            case BARRA_ENERGIA:
                std::cout<<"Recibi nivel de energia: "<<objectType<<std::endl;

                break;
            case VIDAS:
                std::cout<<"Recibi vidas: "<<objectType<<std::endl;

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
            case END_OF_RESPONSE:
                break;
            default:
                return GameState::CONTINUE;
                break;
        }
    return GameState::CONTINUE;
}

ResponseHandler::~ResponseHandler(){
}

