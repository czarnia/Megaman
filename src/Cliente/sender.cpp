#include "sender.h"
#include <utility>
#include <iostream>

// VER PROTOCOLO
Sender::Sender(Socket *socket): skt(socket){
    commands.insert(std::pair<std::string,int>("attack" ,1));
    commands.insert(std::pair<std::string,int>("move"   ,2));
    commands.insert(std::pair<std::string,int>("gunChange",3));
    //ATTACK
    commands.insert(std::pair<std::string,int>("left",4));
    commands.insert(std::pair<std::string,int>("right",3));
    //MOVE
    commands.insert(std::pair<std::string,int>("up"     ,1));
    commands.insert(std::pair<std::string,int>("down"   ,2));
    commands.insert(std::pair<std::string,int>("right"  ,3));
    commands.insert(std::pair<std::string,int>("left"   ,4));
    commands.insert(std::pair<std::string,int>("jump"   ,5));
    //GUN
    commands.insert(std::pair<std::string,int>("gun1"   ,1));
    commands.insert(std::pair<std::string,int>("gun2"   ,2));
    commands.insert(std::pair<std::string,int>("gun3"   ,3));
    commands.insert(std::pair<std::string,int>("gun4"   ,4));
    commands.insert(std::pair<std::string,int>("gun5"   ,5));
}

int Sender::send(std::string command, std::string option){
    skt->send((char*)&(commands[command]), sizeof(int));
    skt->send((char*)&(commands[option]), sizeof(int));
}
