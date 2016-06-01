#include "receiver.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

//TODO:Definir estos valores!
#define MAX_TAM_BUFFER 50
#define END_OF_MAP 666
#define END_OF_RESPONSE 666
#define MAPA 1
#define TAM_INT 4
#define VICTORY 5
#define GAMEOVER 6
#define EARTH_BLOCK 5
#define STAIR_BLOCK 6
#define SPIKE_BLOCK 7
#define MET 8
#define BLOCK_WIDTH 15
#define BLOCK_HEIGHT 15

Receiver::Receiver(Socket* conexion, Renderer &renderer, Mutex &mutex):
                    skt(conexion), renderer(renderer), mutex(mutex){
}

void Receiver::ejecutar(){
    /// Recibo el tamanio del mapa
    receiveMapSize();
    /// Primero recibo el mapa
    /// Las posiciones de los bloques,escaleras,puas, etc
    receiveMap();


    char buffer[TAM_INT] = "";
    int command;
    int option;
    int coordX;
    int coordY;
    std::pair<int,int> coord;
	std::cout<<"Se comenzo a recibir cosas"<<std::endl;
    while (command != END_OF_RESPONSE){
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
            skt->receive(buffer, TAM_INT);
            coordX = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);

            skt->receive(buffer, TAM_INT);
            coordY = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
            coord = std::make_pair(coordX, coordY);
        }

        mutex.lock();
        renderer.execute(command, option, coord);
        mutex.unlock();
    }
    skt->shutdown(SHUT_RDWR);
    return;
}

void Receiver::receiveMapSize(){
    char buffer[TAM_INT] = "";
    int level_width;
    int level_height;
    /// ANCHO
    skt->receive(buffer,TAM_INT);
    level_width = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);
    /// LARGO
    skt->receive(buffer,TAM_INT);
    level_height = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);
    renderer.setMapSize(level_width, level_height);
}

void Receiver::receiveMap(){
    char buffer[TAM_INT] = "";
    int object;
    int coordX = 0;
    int coordY = 0;
    Sprite *spr = NULL;
    do{
        ///OBJETO
        skt->receive(buffer,TAM_INT);
        object = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);
        if (object != END_OF_MAP){
            /// COORD X
            skt->receive(buffer,TAM_INT);
            coordX = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
            /// COORD Y
            skt->receive(buffer,TAM_INT);
            coordY = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);
        }
    }while (object != END_OF_MAP);
    /// CARGO EL OBJETO QUE RECIBI
    switch (object){
        case EARTH_BLOCK:
            spr = new Block_sprite(renderer.get_renderer(), "block.png");
            spr->setPosX(coordX);
            spr->setPosY(coordY);
            renderer.addMapSprite(EARTH_BLOCK, spr);
            break;
        case STAIR_BLOCK:
            spr = new Sprite(renderer.get_renderer(), "");
            break;
        case SPIKE_BLOCK:
            spr = new Sprite(renderer.get_renderer(), "");
            break;
        case MET:
            spr = new Sprite(renderer.get_renderer(), "");
            break;
        default:
            break;
    }
}















