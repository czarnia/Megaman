#include "receiver.h"
#include <iostream>
#include <string.h>
#include "block_sprite.h"
#include "response_handler.h"
#include "character_sprite.h"
#include "backround_sprite.h"
#include "gameState.h"
//TODO:Definir estos valores!
#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666

#define TAM_INT 4
#define MEGAMAN 1
#define VICTORY 5
#define GAMEOVER 6
#define EARTH_BLOCK 100
#define STAIR_BLOCK 1000
#define SPIKE_BLOCK 1200
#define MET 8


Receiver::Receiver(Socket* conexion, Renderer *renderer,
                    bool *victory, bool *ko):
    skt(conexion),
    renderer(renderer),
    victory(victory),
    ko(ko)
{
}

void Receiver::update(){
    /// Ahora recibo las actualizaciones de las cosas movibles
    /// o que pueden cambiar
    static ResponseHandler handler(renderer);
    int command;
    int option;
    int coordX;
    int coordY;
    std::pair<int,int> coord;
	std::cout<<"Se comenzo a recibir cosas"<<std::endl;

    char buffer[TAM_INT] = "";
    /// COMANDO
    skt->receive(buffer, TAM_INT);
    command = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);
    /// OPCION
    skt->receive(buffer, TAM_INT);
    option = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);

    if ( (command != VICTORY) && (command != GAMEOVER)){
        /// COORDX
        skt->receive(buffer, TAM_INT);
        coordX = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        /// COORDY
        skt->receive(buffer, TAM_INT);
        coordY = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        coord = std::make_pair(coordX, coordY);
    }

    switch (handler.execute(command, option, coord)){
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
    int object;
    int coordX = 0;
    int coordY = 0;
    Sprite *spr = NULL;
    do{
        /// recibo COMANDO y lo ignoro aca
        /*skt->receive(buffer,TAM_INT);
        command = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);*/
        /// Recibo OBJETO
        skt->receive(buffer,TAM_INT);
        object = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        if (object != END_OF_MAP){
            /// Recibo COORD X
            skt->receive(buffer,TAM_INT);
            coordX = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
            /// Recibo COORD Y
            skt->receive(buffer,TAM_INT);
            coordY = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
        }
        std::cout<<"Recibi MAPA: "<< object<< " " << coordX << " " << coordY<<std::endl;
        /// CARGO EL OBJETO QUE RECIBI
        switch (object){
            case MEGAMAN:
                spr = new Main_character(renderer->get_renderer(), "../sprites/megaman.jpeg");
                spr->setPosX(coordX*15);
                spr->setPosY(coordY*15);
                renderer->addSprite(MEGAMAN,spr);
            case EARTH_BLOCK:
                spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
                spr->setPosX(coordX*15);
                spr->setPosY(coordY*15);
                renderer->addMapSprite(EARTH_BLOCK, spr);
                break;
            case STAIR_BLOCK:
                spr = new Block_sprite(renderer->get_renderer(), "../sprites/stair_block.png");
                spr->setPosX(coordX);
                spr->setPosY(coordY);
                renderer->addMapSprite(STAIR_BLOCK, spr);
                break;
            case SPIKE_BLOCK:
                spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike_block.png");
                spr->setPosX(coordX);
                spr->setPosY(coordY);
                renderer->addMapSprite(SPIKE_BLOCK, spr);
                break;
            case MET:
                /// Recibo el met y luego QUE met
                spr = new Sprite(renderer->get_renderer(), "");
                break;
            default:
                break;
        }
    }while (object != END_OF_MAP);
}

Receiver::~Receiver(){
    skt->shutdown(SHUT_RDWR);
}













