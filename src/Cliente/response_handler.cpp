#include "response_handler.h"
#include <iostream>
#include "character_sprite.h"
#include "minion_sprite.h"
#include "bullet_sprite.h"
#include "gameState.h"
#include "pickable_sprite.h"

#define STATIC 1
#define NON_STATIC 0
#define FRONT 1
#define BACK 0
#define BIG true
#define SMALL false

#define SCALE_FACTOR 1

/// PARA PROTOCOLO
#define MAPA 1
#define HP_BAR 2
#define MP_BAR 3
#define LIFE 4
#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666
#define MEGAMAN 1
#define MEGAMAN_BULLET 12
#define BUMBY 2
#define J_SNIPER 3
#define MET 4
#define SNIPER 5
#define SMALL_HP 14
#define BIG_HP 15
#define SMALL_MP 16
#define BIG_MP 17

#define LEVEL_COMPLETE 5
#define VICTORY 7
#define GAMEOVER 6

/// PARA ALMACENAMIENTO
#define BLOCK_EARTHN 100
#define BLOCK_SPIKESN 1000
#define BLOCK_LADDERN 1500
#define MEGAMANN 0
#define MEGAMAN_BULLETN 10000
#define BUMBYN 2000
#define J_SNIPERN 3000
#define METN 4000
#define SNIPERN 5000
#define LIFEN 5500
#define BIG_HPN 5510
#define SMALL_HPN 5520
#define BIG_MPN 5530
#define SMALL_MPN 5540
#define HP_BARN 6000
#define MP_BARN 6010

/// Auxiliar
void sortObject(int *objectType){
    if (*objectType == MEGAMAN){
        *objectType = MEGAMANN;
    }else if (*objectType == MEGAMAN_BULLET){
        *objectType = MEGAMAN_BULLETN;
    }else if (*objectType == MET){
        *objectType = METN;
    }else if (*objectType == BUMBY){
        *objectType = BUMBYN;
    }else if (*objectType == J_SNIPER){
        *objectType = J_SNIPERN;
    }else if (*objectType == SNIPER){
        *objectType = SNIPERN;
    }else if (*objectType == LIFE){
        *objectType = LIFEN;
    }else if (*objectType == BIG_HP){
        *objectType = BIG_HPN;
    }else if (*objectType == SMALL_HP){
        *objectType = SMALL_HPN;
    }else if (*objectType == BIG_MP){
        *objectType = BIG_MPN;
    }else if (*objectType == SMALL_MP){
        *objectType = SMALL_MPN;
    }else if (*objectType == HP_BAR){
        *objectType = HP_BARN;
    }else if (*objectType == MP_BAR){
        *objectType = MP_BARN;
    }else{
        *objectType = -1;
    }

}

ResponseHandler::ResponseHandler(Renderer *renderer):
    renderer(renderer)
{
}

void ResponseHandler::createObject(int objectType, int objectID, std::pair<int,int> coord){
    Sprite *spr = NULL;
    switch (objectType){
        case MEGAMANN:
            spr = new Character_sprite(renderer->get_renderer(),"../sprites/8bitmegaman.png");
            spr->loadAnimations("../AnimationConfig/megaman.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            renderer->sprites[FRONT][objectType+objectID]->spawn();
            break;
        case METN:
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/met.png");
            spr->loadAnimations("../AnimationConfig/met.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case BUMBYN:
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/bumby.PNG");
            spr->loadAnimations("../AnimationConfig/bumby.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case J_SNIPERN:
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/j_sniper.png");
            spr->loadAnimations("../AnimationConfig/j_sniper.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
                break;
        case SNIPERN:
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/sniper.png");
            spr->loadAnimations("../AnimationConfig/sniper.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
            case MEGAMAN_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/bullet.jpeg");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case BIG_HP:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/big_hp.png", BIG);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case SMALL_HP:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/small_hp.png", SMALL);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case BIG_MP:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/big_mp.png", BIG);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case SMALL_MP:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/small_mp.png", SMALL);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case LIFE:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/life.png", BIG);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
    }
}

void ResponseHandler::changeHUD(int bar, int barID, int ammount){
    renderer->static_sprites[FRONT][bar+barID]->setAmmount(ammount);
}

int ResponseHandler::execute(int command, int objectType, int objectID, std::pair<int,int> coord){


    coord.first *= SCALE_FACTOR;
    coord.second *= SCALE_FACTOR;
    /// Etapa de clasificacion de objetos
    sortObject(&objectType);

    switch (command){
        case MAPA:
            /// SI recibi coordenadas negativas destruyo el objeto
            if (coord.first < 0){
                /// SI HAY QUE HACER ALGUNA ANIMACION DE DESTRUCCION
                /// LA METO ACA
                //renderer->sprites[FRONT][objectType+objectID]->destroy();
                renderer->erase(objectType+objectID);
            /// SI ya existe le cambio la posicion
            }else if (renderer->find(objectType+objectID)){
                /// ANIMACION DE MOVIMIENTO
                renderer->sprites[FRONT][objectType+objectID]->setState(coord.first, coord.second);
                renderer->sprites[FRONT][objectType+objectID]->setPosX(coord.first);
                renderer->sprites[FRONT][objectType+objectID]->setPosY(coord.second);
            /// Si no existe lo creo y le seteo la posicion
            }else{
                createObject(objectType, objectID, coord);
            }
            break;
        case HP_BAR:
            changeHUD(objectType, objectID, coord.first);
            break;
        case MP_BAR:
            changeHUD(objectType, objectID, coord.first);
            break;
        case LIFE:
            changeHUD(objectType, objectID, coord.first);
            break;
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
