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
#define ACTION 5
#define LEVEL_COMPLETE 6
#define VICTORY 8
#define GAMEOVER 7

#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666
#define MEGAMAN 1
#define BUMBY 2
#define J_SNIPER 3
#define MET 4
#define SNIPER 5
#define SMALL_HP 14
#define BIG_HP 15
#define SMALL_MP 16
#define BIG_MP 17

#define BOMBMAN_BULLET 30
#define MAGNETMAN_BULLET 31
#define SPARKMAN_BULLET 32
#define RINGMAN_BULLET 33
#define FIREMAN_BULLET 34
#define MEGAMAN_BULLET 35
#define MINION_BULLET 36

/// PARA ALMACENAMIENTO
#define BLOCK_EARTHN 100
#define BLOCK_SPIKESN 1000
#define BLOCK_LADDERN 1500
#define MEGAMANN 0
#define MEGAMAN_BULLETN 10000
#define BOMBMAN_BULLETN 20000
#define MAGNETMAN_BULLETN 30000
#define SPARKMAN_BULLETN 40000
#define RINGMAN_BULLETN 50000
#define FIREMAN_BULLETN 60000
#define MINION_BULLETN 70000
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
    }else if (*objectType == BOMBMAN_BULLET){
        *objectType = BOMBMAN_BULLETN;
    }else if (*objectType == MAGNETMAN_BULLET){
        *objectType = MAGNETMAN_BULLETN;
    }else if (*objectType == SPARKMAN_BULLET){
        *objectType = SPARKMAN_BULLETN;
    }else if (*objectType == RINGMAN_BULLET){
        *objectType = RINGMAN_BULLETN;
    }else if (*objectType == FIREMAN_BULLET){
        *objectType = FIREMAN_BULLETN;
    }else if (*objectType == MINION_BULLET){
        *objectType = MINION_BULLETN;
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
      //  *objectType = -1;
    }

}

ResponseHandler::ResponseHandler(Renderer *renderer):
    renderer(renderer)
{
}

void ResponseHandler::createObject(int &objectType, int &objectID, std::pair<int,int> &coord){
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
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/met.png", 0);
            spr->loadAnimations("../AnimationConfig/met.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case BUMBYN:
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/bumby.PNG", 0);
            spr->loadAnimations("../AnimationConfig/bumby.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case J_SNIPERN:
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/j_sniper.PNG", 1);
            spr->loadAnimations("../AnimationConfig/j_sniper.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
                break;
        case SNIPERN:
            spr = new Minion_sprite(renderer->get_renderer(),"../sprites/sniper.PNG", 1);
            spr->loadAnimations("../AnimationConfig/sniper.txt");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case MEGAMAN_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/megaman_bullet.png");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case BOMBMAN_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/bombman_bullet.png");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case MAGNETMAN_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/magnetman_bullet.png");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case SPARKMAN_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/sparkman_bullet.png");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case RINGMAN_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/ringman_bullet.png");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case FIREMAN_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/fireman_bullet.png");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case MINION_BULLETN:
            spr = new Bullet_sprite(renderer->get_renderer(),"../sprites/minion_bullet.png");
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case BIG_HPN:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/big_hp.png", BIG);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case SMALL_HPN:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/small_hp.png", SMALL);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case BIG_MPN:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/big_mp.png", BIG);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case SMALL_MPN:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/small_mp.png", SMALL);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
        case LIFEN:
            spr = new Pickable_sprite(renderer->get_renderer(), "../sprites/life.png", BIG);
            spr->setPosX(coord.first);
            spr->setPosY(coord.second);
            renderer->addSprite(objectType+objectID, spr, FRONT, NON_STATIC);
            break;
    }
}

void ResponseHandler::changeHUD(int bar, int &barID, int &ammount){
   // renderer->static_sprites[FRONT][bar+barID]->setAmmount(ammount);
}

void ResponseHandler::executeAction(int &objectType, int &objectID, int &action){
    renderer->sprites[FRONT][objectType+objectID]->setState(action);
}

void ResponseHandler::changePosition(int &objectType, int &objectID, std::pair<int,int> &coord){
    /// PARA LA ANIMACION
   // renderer->sprites[FRONT][objectType+objectID]->changeState(coord.first, coord.second);
    renderer->sprites[FRONT][objectType+objectID]->setPosX(coord.first);
    renderer->sprites[FRONT][objectType+objectID]->setPosY(coord.second);
}

int ResponseHandler::execute(int command, int objectType, int objectID, std::pair<int,int> option){

    /// Etapa de clasificacion de objetos
    sortObject(&objectType);

    switch (command){
        case MAPA:
            option.first *= SCALE_FACTOR;
            option.second *= SCALE_FACTOR;
            /// SI recibi coordenadas negativas destruyo el objeto
            if (option.first < 0){
                /// SI HAY QUE HACER ALGUNA ANIMACION DE DESTRUCCION
                /// LA METO ACA
                //renderer->sprites[FRONT][objectType+objectID]->destroy();
                renderer->erase(objectType+objectID);
            /// SI ya existe le cambio la posicion
            }else if (renderer->find(objectType+objectID)){
                changePosition(objectType, objectID, option);
            }else{
                /// Si no existe lo creo y le seteo la posicion
                createObject(objectType, objectID, option);
            }
            break;
        case HP_BAR:
            changeHUD(HP_BARN, objectID, option.first);
            break;
        case MP_BAR:
            changeHUD(MP_BARN, objectID, option.first);
            break;
        case LIFE:
            changeHUD(LIFEN, objectID, option.first);
            break;
        case ACTION:
            executeAction(objectType, objectID, option.first);
            break;
        case VICTORY:
            std::cout<<"Recibi victoria: Vuelvo a boss select"<<std::endl;
            return GameState::BOSS_SELECT;
            break;
        case GAMEOVER:
            std::cout<<"Recibi gameover: Vuelvo al menu inicio"<<std::endl;
            return GameState::GAME_OVER;
            break;
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

