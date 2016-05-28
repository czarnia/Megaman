#include "receiver.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

//TODO:Definir estos valores!
#define MAX_TAM_BUFFER 50
#define FIN_ENTRADA 666
#define MAPA 1

Receiver::Receiver(Socket* conexion, Renderer &renderer, Mutex &mutex):
                    skt(conexion), renderer(renderer), mutex(mutex){
}

void Receiver::ejecutar(){
    char buffer[MAX_TAM_BUFFER] = "";
    int command;
    int option;
    int coordX;
    int coordY;
    std::pair<int,int> coord;

    while (command != FIN_ENTRADA){
        skt->receiveInt(&command, sizeof(int));
        skt->receiveInt(&option, sizeof(int));

        if (command == MAPA){
            skt->receiveInt(&coordX, sizeof(int));
            skt->receiveInt(&coordY, sizeof(int));
            coord = std::make_pair(coordX, coordY);
        }

        mutex.lock();
        renderer.execute(command, option, coord);
        mutex.unlock();
    }
    skt->shutdown(SHUT_RDWR);
    return;
}
