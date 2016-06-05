#include "receiver.h"
#include <iostream>
#include <string.h>
#include "block_sprite.h"
#include "response_handler.h"
#include "character_sprite.h"
#include "backround_sprite.h"
#include "minion_sprite.h"
#include "gameState.h"
//TODO:Definir estos valores!
#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666

#define BLOCK 0
#define MEGAMAN 1
#define BULLET 2
#define MET 8

#define TAM_INT 4
#define VICTORY 5
#define GAMEOVER 6




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

    if ( (command != VICTORY) && (command != GAMEOVER) && (command != END_OF_RESPONSE)){
        /// Tipo de objeto
        skt->receive(buffer, TAM_INT);
        objectType = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        /// numero de objeto
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
        coord = std::make_pair(coordX, coordY);
    }else{
        objectType = -1;
        objectID = -1;
        coordX = -1;
        coordY = -1;
    }
    /// Etapa de clasificacion de objetos
    if (objectType == BLOCK){
        objectType += 100;
    }else if (objectType == MEGAMAN){
        objectType -= 1;
    }else if (objectType == BULLET){
        objectType += 48;
    }

    switch (handler.execute(command, objectType, objectID, coord)){
        case GameState::BOSS_SELECT:
            *victory = true;
            break;
        case GameState::GAME_OVER:
            *ko = true;
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
    renderer->setMapSize(level_width, level_height);
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
      /*  skt->receive(buffer,TAM_INT);
        command = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);*/
        /// Recibo el tipo de OBJETO
        skt->receive(buffer,TAM_INT);
        objectType = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        /// Recibo el id del OBJETO
        skt->receive(buffer,TAM_INT);
        objectID = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        if (objectType != END_OF_MAP){
            /// Recibo COORD X
            skt->receive(buffer,TAM_INT);
            coordX = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
            /// Recibo COORD Y
            skt->receive(buffer,TAM_INT);
            coordY = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
        }
        std::cout<<"Recibi MAPA: "<< objectType<< " " << coordX << " " << coordY<<std::endl;
        /// CARGO EL OBJETO QUE RECIBI
        switch (objectType){
            case BLOCK:
                spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
                spr->setPosX(coordX*30);
                spr->setPosY(coordY*30);
                renderer->addMapSprite(BLOCK+100, spr);
                break;
            case MEGAMAN:
                spr = new Main_character(renderer->get_renderer(), "../sprites/megaman.jpeg");
                spr->setPosX(coordX*30);
                spr->setPosY(coordY*30);
                renderer->addSprite(MEGAMAN+objectID-1,spr);
            case MET:
                spr = new Minion_sprite(renderer->get_renderer(), "../sprites/met.png");
                spr->setPosX(coordX*30);
                spr->setPosY(coordY*30);
                renderer->addMapSprite(MET+objectID, spr);
                break;
            default:
                break;
        }
    }while (objectType != END_OF_MAP);
}

Receiver::~Receiver(){
    skt->shutdown(SHUT_RDWR);
}













