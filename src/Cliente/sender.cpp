#include "sender.h"
#include <utility>


#define TAM_INT 4
// VER PROTOCOLO
Sender::Sender(Socket *socket): skt(socket){
    commands.insert(std::pair<const char*,int>("attack" ,1));
    commands.insert(std::pair<const char*,int>("move"   ,2));
    commands.insert(std::pair<const char*,int>("gunChange",3));
    commands.insert(std::pair<const char*,int>("up"     ,1));
    commands.insert(std::pair<const char*,int>("down"   ,2));
    commands.insert(std::pair<const char*,int>("right"  ,3));
    commands.insert(std::pair<const char*,int>("left"   ,4));
    commands.insert(std::pair<const char*,int>("gun1"   ,1));
    commands.insert(std::pair<const char*,int>("gun2"   ,2));
    commands.insert(std::pair<const char*,int>("gun3"   ,3));
    commands.insert(std::pair<const char*,int>("gun4"   ,4));
    commands.insert(std::pair<const char*,int>("gun5"   ,5));
}

int Sender::send(const char* command, const char* option){
    skt->sendInt(&commands[command], sizeof(int));
    if(!strncmp(command, "attack"))
        skt->sendInt(&commands[option], sizeof(int));
}
