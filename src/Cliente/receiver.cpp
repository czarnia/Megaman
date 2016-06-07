#include "receiver.h"
#include <iostream>
#include <string.h>
#include "block_sprite.h"
#include "response_handler.h"
#include "character_sprite.h"
#include "backround_sprite.h"
#include "minion_sprite.h"
#include "gameState.h"

#define MAPA 1
/// PARA PROTOCOLO
#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666
#define BLOCK_EARTH 10
#define BLOCK_SPIKES 11
#define BLOCK_STAIR 12
#define MEGAMAN 1
#define MEGAMAN_BULLET 2
#define MET 8

/// PARA ALMACENAMIENTO
#define BLOCK_EARTHN 100
#define BLOCK_SPIKESN 1000
#define BLOCK_STAIRN 1500
#define MEGAMANN 0
#define MEGAMAN_BULLETN 10000
#define METN 2000

#define TAM_INT 4
#define VICTORY 2
#define GAMEOVER 3

Receiver::Receiver(Socket* conexion, Renderer *renderer,
                    bool *victory, bool *ko):
    skt(conexion),
    renderer(renderer),
    victory(victory),
    ko(ko)
{
}

void Receiver::update(bool *running){
    /// Ahora recibo las actualizaciones de las cosas movibles
    /// o que pueden cambiar
    static ResponseHandler handler(renderer);
    int command;
    int objectType;
    int objectID;
    int coordX;
    int coordY;
    std::pair<int,int> coord;
	std::cout<<"Se comenzo a recibir cosas"<<std::endl;

    char buffer[TAM_INT] = "";
    /// COMANDO
    skt->receive(buffer, TAM_INT);
    command = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);

    if ( command == MAPA ){
        /// Tipo de objeto
        skt->receive(buffer, TAM_INT);
        objectType = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        /// ID objeto
        skt->receive(buffer, TAM_INT);
        objectID = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        /// COORDX
        skt->receive(buffer, TAM_INT);
        coordX = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        /// COORDY
        skt->receive(buffer, TAM_INT);
        coordY = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);

        coordX *= 30;
        coordY *= 30;
        coord = std::make_pair(coordX, coordY);

            /// Etapa de clasificacion de objetos
        if (objectType == MEGAMAN){
            objectType = MEGAMANN;
        }else if (objectType == MEGAMAN_BULLET){
            objectType = MEGAMAN_BULLETN;
        }else if (objectType == MET){
            objectType = METN;
        }
    }else{
        objectType = -1;
        objectID = -1;
        coordX = -1;
        coordY = -1;
    }

    switch (handler.execute(command, objectType, objectID, coord)){
        case GameState::BOSS_SELECT:
            *victory = true;
            break;
        case GameState::GAME_OVER:
            *ko = true;
            break;
        default:
            break;
    }
    return;
}

void Receiver::receiveMapSize(){
    char buffer[TAM_INT] = "";
    int level_width = 0;
    int level_height = 0;
    /// ANCHO
    skt->receive(buffer,TAM_INT);
    level_width = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);
    /// LARGO
    skt->receive(buffer,TAM_INT);
    level_height = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);
    renderer->setMapSize(level_width*30, level_height*30);
    std::cout<<"Recibi tamanio del mapa: "<<level_width<<"x"<<level_height<<std::endl;
}

void Receiver::receiveMap(){
    char buffer[TAM_INT] = "";
    int command;
    int objectType;
    int objectID;
    int coordX = 0;
    int coordY = 0;
    Sprite *spr = NULL;
    do{
        /// recibo COMANDO y lo ignoro aca
        skt->receive(buffer,TAM_INT);
        command = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        if (command != END_OF_MAP){
            /// Recibo el tipo de OBJETO
            skt->receive(buffer,TAM_INT);
            objectType = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
            /// Recibo el id del OBJETO
            skt->receive(buffer,TAM_INT);
            objectID = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
            /// Recibo COORD X
            skt->receive(buffer,TAM_INT);
            coordX = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
            /// Recibo COORD Y
            skt->receive(buffer,TAM_INT);
            coordY = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);

            std::cout<<command << " "<< objectType<< " " << coordX << " " << coordY<<std::endl;
            /// CARGO EL OBJETO QUE RECIBI
            switch (objectType){
                case BLOCK_EARTH:
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
                    spr->setPosX(coordX*30);
                    spr->setPosY(coordY*30);
                    renderer->addMapSprite(BLOCK_EARTHN, spr);
                    break;
                case BLOCK_SPIKES:
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.gif");
                    spr->setPosX(coordX*30);
                    spr->setPosY(coordY*30);
                    renderer->addMapSprite(BLOCK_SPIKESN, spr);
                    break;
                case BLOCK_STAIR:
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/stair.jpeg");
                    spr->setPosX(coordX*30);
                    spr->setPosY(coordY*30);
                    renderer->addMapSprite(BLOCK_STAIRN, spr);
                    break;
                case MEGAMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/megaman.png");
                    spr->setPosX(coordX*30);
                    spr->setPosY(coordY*30);
                    renderer->addSprite(MEGAMANN+objectID,spr);
                case MET:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/met.png");
                    spr->setPosX(coordX*30);
                    spr->setPosY(coordY*30);
                    renderer->addMapSprite(METN+objectID, spr);
                    break;
                default:
                    break;
            }
        }
    }while (command != END_OF_MAP);
}

Receiver::~Receiver(){
    skt->shutdown(SHUT_RDWR);
}













