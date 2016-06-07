#include "response_handler.h"
#include <iostream>
#include "character_sprite.h"
#include "minion_sprite.h"
#include "bullet_sprite.h"
#include "gameState.h"

#define MAPA 1
/// PARA PROTOCOLO
#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666
#define VICTORY 2
#define GAMEOVER 3

/// PARA ALMACENAMIENTO
#define BLOCK_EARTHN 100
#define BLOCK_SPIKESN 1000
#define BLOCK_STAIRN 1500
#define MEGAMANN 0
#define MEGAMAN_BULLETN 10000
#define METN 2000

ResponseHandler::ResponseHandler(Renderer *renderer):
    renderer(renderer)
{
}

int ResponseHandler::execute(int command, int objectType, int objectID, std::pair<int,int> coord){
    Sprite *spr = NULL;
    switch (command){
        case MAPA:
            /// SI recibi coordenadas negativas destruyo el objeto
            if (coord.first < 0){
                renderer->erase(objectType+objectID);
            /// SI ya existe le cambio la posicion
            }else if (renderer->find(objectType+objectID)){
                renderer->sprites[objectType+objectID]->setPosX(coord.first);
                renderer->sprites[objectType+objectID]->setPosY(coord.second);
            /// Si no existe lo creo y le seteo la posicion
            }else{
                switch (objectType){
                    case MEGAMANN:
                        spr = new Character_sprite(renderer->get_renderer(),"../sprites/megaman.png");
                        spr->setPosX(coord.first);
                        spr->setPosY(coord.second);
                        renderer->addSprite(objectType+objectID, spr);
                        break;
                    case METN:
                        spr = new Minion_sprite(renderer->get_renderer(),"../sprites/met.png");
                        spr->setPosX(coord.first);
                        spr->setPosY(coord.second);
                        renderer->addSprite(objectType+objectID, spr);
                        break;
                    case MEGAMAN_BULLETN:
                        spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/bullet.png");
                        spr->setPosX(coord.first);
                        spr->setPosY(coord.second);
                        renderer->addSprite(objectType+objectID, spr);
                        break;
                }
            }
            break;
  /*      case BARRA_VIDA:
            std::cout<<"Recibi nivel de vida: "<<objectType<<std::endl;

            break;
        case BARRA_ENERGIA:
            std::cout<<"Recibi nivel de energia: "<<objectType<<std::endl;

            break;
        case VIDAS:
            std::cout<<"Recibi vidas: "<<objectType<<std::endl;

            break;*/

        case VICTORY:{
            std::cout<<"Recibi victoria: Vuelvo a boss select"<<std::endl;
            return GameState::BOSS_SELECT;
            break;
        }
        case GAMEOVER:{
            std::cout<<"Recibi gameover: Vuelvo al menu inicio"<<std::endl;
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

