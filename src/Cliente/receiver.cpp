#include "receiver.h"
#include <iostream>
#include "block_sprite.h"
#include "character_sprite.h"
#include "background_sprite.h"
#include "minion_sprite.h"
#include "gameState.h"

#define STATIC 1
#define NON_STATIC 0

#define SCALE_FACTOR 15

/// PARA PROTOCOLO
#define MAPA 1
#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666
#define BLOCK_EARTH 10
#define BLOCK_SPIKES 11
#define BLOCK_LADDER 12
#define MEGAMAN 1
#define MEGAMAN_BULLET 12
#define BUMBY 2
#define J_SNIPER 3
#define MET 4
#define SNIPER 5

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

#define FRONT 1
#define BACK 0


#define TAM_INT 4
#define VICTORY 2
#define GAMEOVER 3

Receiver::Receiver(Socket* conexion, Renderer *renderer,
                    Mutex *mutex):
    skt(conexion),
    renderer(renderer),
    mutex(mutex)
{
}

/// HILO
void Receiver::ejecutar(){
    /// Ahora recibo las actualizaciones de las cosas movibles
    /// o que pueden cambiar
    int command;
    int objectType;
    int objectID;
    int coordX;
    int coordY;
    std::pair<int,int> coord;
	std::cout<<"Se comenzo a recibir cosas:"<<std::endl;
    while (command != END_OF_RESPONSE){
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
            ////////////////
            std::cout<<"Recibi comando: "<<command << " Tipo de Objeto: "
            << objectType << " ID de objeto: "<<objectID <<" Pos: "
            <<coordX<<","<<coordY<<std::endl;
            ///////////////
            coordX *= SCALE_FACTOR;
            coordY *= SCALE_FACTOR;
            /// Etapa de clasificacion de objetos
            if (objectType == MEGAMAN){
                objectType = MEGAMANN;
            }else if (objectType == MEGAMAN_BULLET){
                objectType = MEGAMAN_BULLETN;
            }else if (objectType == MET){
                objectType = METN;
            }else if (objectType == BUMBY){
                objectType = BUMBYN;
            }else if (objectType == J_SNIPER){
                objectType = J_SNIPERN;
            }else if (objectType == SNIPER){
                objectType = SNIPERN;
            }else{
                objectType = -1;
                objectID = -1;
                coordX = -1;
                coordY = -1;
            }
            mutex->lock();
            r_queue.push(new Event(command,objectType,objectID,coordX,coordY));
            mutex->unlock();
        }else{
            mutex->lock();
            r_queue.push(new Event(command));
            mutex->unlock();
        }
    }
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
    renderer->setMapSize(level_width*15, level_height*15);
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
    std::cout << "Comence a recibir mapa"<<std::endl;
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

            std::cout<< "Recibo comando: "<<command << " "
            <<"Tipo de objeto: "<< objectType<< " " <<
            "Posicion: "<< coordX << "," << coordY<<std::endl;
            /// CARGO EL OBJETO QUE RECIBI
            switch (objectType){
                case BLOCK_EARTH:
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BLOCK_EARTHN, spr, BACK, NON_STATIC);
                    break;
                case BLOCK_SPIKES:
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.gif");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BLOCK_SPIKESN, spr, BACK, NON_STATIC);
                    break;
                case BLOCK_LADDER:
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/stair.jpeg");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BLOCK_LADDERN, spr, BACK, NON_STATIC);
                    break;
                case MEGAMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/8bitmegaman.png");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(MEGAMANN+objectID, spr, 1, NON_STATIC);
                    break;
                case MET:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/met.png");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(METN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case BUMBY:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/bumby.png");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BUMBYN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case J_SNIPER:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/j_sniper.png");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(J_SNIPERN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case SNIPER:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/sniper.png");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(SNIPERN+objectID, spr, FRONT, NON_STATIC);
                    break;
                default:
                    break;
            }
        }
    }while (command != END_OF_MAP);
}

Receiver::~Receiver(){

}













