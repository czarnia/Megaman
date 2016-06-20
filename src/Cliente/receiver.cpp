#include "receiver.h"
#include <iostream>
#include <sstream>
#include "block_sprite.h"
#include "character_sprite.h"
#include "background_sprite.h"
#include "response_handler.h"
#include "minion_sprite.h"
#include "gameState.h"

#define STATIC 1
#define NON_STATIC 0

#define SCALE_FACTOR 1

/// PARA PROTOCOLO
#define MAPA 1
#define END_OF_MAP 6666
#define END_OF_RESPONSE 6666
#define BLOCK_EARTH 10
#define BLOCK_SPIKES 11
#define BLOCK_LADDER 12
#define MEGAMAN 1
#define BUMBY 2
#define J_SNIPER 3
#define MET 4
#define SNIPER 5
#define BOMBMAN 20
#define MAGNETMAN 21
#define SPARKMAN 22
#define RINGMAN 23
#define FIREMAN 24

/// PARA ALMACENAMIENTO
#define BLOCK_EARTHN 100
#define BLOCK_SPIKESN 1000
#define BLOCK_LADDERN 1500
#define MEGAMANN 0
#define BOMBMANN 5
#define MAGNETMANN 6
#define SPARKMANN 7
#define RINGMANN 8
#define FIREMANN 9
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
    /// o que pueden cambiar, las recibo en forma de eventos
	std::cout<<"Se comenzo a recibir cosas:"<<std::endl;
	bool end = false;
    while (!end){
        receiveEventAndQueue(&end);
    }
}

void Receiver::receiveEventAndQueue(bool *end){

    ResponseHandler handler(renderer);

    int command;
    int objectType;
    int objectID;
    int coordX;
    int coordY;
    std::pair<int,int> coord;
    char buffer[TAM_INT] = "";

    /// COMANDO
    skt->receive(buffer, TAM_INT);
    command = *((int*)buffer);
    strncpy(buffer,"    ",TAM_INT);
    if ( command != END_OF_RESPONSE){
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
        std::pair<int,int> coord;
        coord.first = coordX;
        coord.second = coordY;
       /* mutex->lock();
        handler.execute(command, objectType, objectID, coord);
        mutex->unlock();*/
        mutex->lock();
        r_queue.push(Event(command,objectType,objectID,coordX,coordY));
        mutex->unlock();
    }else{
        *end = true;
    }
   /* mutex->lock();
    renderer->clear();
    renderer->drawAll();
    renderer->present();
    mutex->unlock();*/
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
    renderer->setMapSize(level_width*Block_sprite::width, level_height*Block_sprite::height);
    std::cout<<"Recibi tamanio del mapa: "<<level_width<<"x"<<level_height<<std::endl;
}

void Receiver::receiveMap(const int &level){

    std::ostringstream bs;
    bs<<"../sprites/block"<<level<<".png";
    std::string blockpath(bs.str());

    std::ostringstream ls;
    ls<<"../sprites/ladder"<<level<<".png";
    std::string ladderpath(ls.str());

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
        skt->receiveInt(&command,TAM_INT);
       /* command = *((int*)buffer);
        strncpy(buffer,"    ",TAM_INT);*/
        if (command != END_OF_MAP){
            /// Recibo el tipo de OBJETO
            skt->receiveInt(&objectType,TAM_INT);
           /* objectType = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);*/
            /// Recibo el id del OBJETO
            skt->receiveInt(&objectID,TAM_INT);
            /*objectID = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);*/
            /// Recibo COORD X
            skt->receiveInt(&coordX,TAM_INT);
            /*coordX = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);*/
            /// Recibo COORD Y
            skt->receiveInt(&coordY,TAM_INT);
            /*coordY = *((int*)buffer);
            strncpy(buffer,"    ",TAM_INT);*/

            std::cout<< "Recibo comando: "<<command << " "
            <<"Tipo de objeto: "<< objectType<< " " <<
            "Posicion: "<< coordX << "," << coordY<<std::endl;
            /// CARGO EL OBJETO QUE RECIBI
            switch (objectType){
                case BLOCK_EARTH:
                    spr = new Block_sprite(renderer->get_renderer(), blockpath.c_str());
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BLOCK_EARTHN, spr, BACK, NON_STATIC);
                    break;
                case BLOCK_SPIKES:
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.png");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BLOCK_SPIKESN, spr, BACK, NON_STATIC);
                    break;
                case BLOCK_LADDER:
                    spr = new Block_sprite(renderer->get_renderer(), ladderpath.c_str());
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BLOCK_LADDERN, spr, BACK, NON_STATIC);
                    break;
                case MEGAMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/8bitmegaman.png");
                    spr->loadAnimations("../AnimationConfig/megaman.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(MEGAMANN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case MET:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/met.PNG", 0);
                    spr->loadAnimations("../AnimationConfig/met.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(METN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case BUMBY:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/bumby.PNG", 0);
                    spr->loadAnimations("../AnimationConfig/bumby.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BUMBYN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case J_SNIPER:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/j_sniper.PNG", 1);
                    spr->loadAnimations("../AnimationConfig/j_sniper.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(J_SNIPERN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case SNIPER:
                    spr = new Minion_sprite(renderer->get_renderer(), "../sprites/sniper.PNG", 1);
                    spr->loadAnimations("../AnimationConfig/sniper.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(SNIPERN+objectID, spr, FRONT, NON_STATIC);
                    break;
                case BOMBMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/bombman.gif");
                    spr->loadAnimations("../AnimationConfig/bombman.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(BOMBMANN, spr, FRONT, NON_STATIC);
                    break;
                case MAGNETMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/magnetman.gif");
                    spr->loadAnimations("../AnimationConfig/magnetman.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(MAGNETMANN, spr, FRONT, NON_STATIC);
                    break;
                case SPARKMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/sparkman.PNG");
                    spr->loadAnimations("../AnimationConfig/sparkman.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(SPARKMANN, spr, FRONT, NON_STATIC);
                    break;
                case RINGMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/ringman.PNG");
                    spr->loadAnimations("../AnimationConfig/ringman.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(RINGMANN, spr, FRONT, NON_STATIC);
                    break;
                case FIREMAN:
                    spr = new Character_sprite(renderer->get_renderer(), "../sprites/fireman.PNG");
                    spr->loadAnimations("../AnimationConfig/fireman.txt");
                    spr->setPosX(coordX*SCALE_FACTOR);
                    spr->setPosY(coordY*SCALE_FACTOR);
                    renderer->addSprite(FIREMANN, spr, FRONT, NON_STATIC);
                    break;
                default:
                    break;
            }
        }
    }while (command != END_OF_MAP);
}

Receiver::~Receiver(){

}













