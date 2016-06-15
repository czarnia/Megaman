#include "lobbyreceiver.h"
#include <iostream>
#define TAM_INT 4

LobbyReceiver::LobbyReceiver(Socket* conexion, Renderer *renderer,
                    Mutex *mutex):
    skt(conexion),
    renderer(renderer),
    mutex(mutex)
{
}

    /// HILO
void LobbyReceiver::ejecutar(){
    char buffer[TAM_INT] = "";
    int start;
    int bossNumber;
    /// START
    skt->receive(buffer, TAM_INT);
    start = *((int*)&buffer);
    strncpy(buffer, "    ", TAM_INT);
    /// numero de boss
    skt->receive(buffer, TAM_INT);
    bossNumber = *((int*)&buffer);
    strncpy(buffer, "    ", TAM_INT);
    std::cout<< "Recibi: "<<start<<" y: "<<bossNumber<<std::endl;
    mutex->lock();
    r_queue.push(start);
    r_queue.push(bossNumber);
    mutex->unlock();
}

LobbyReceiver::~LobbyReceiver(){

}














