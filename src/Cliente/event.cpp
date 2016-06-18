#include "event.h"

Event::Event(int command, int objectType, int objectID,
                int posX, int posY):
    command(command),
    objectType(objectType),
    objectID(objectID),
    posX(posX),
    posY(posY)
{

}

Event& Event::operator=(Event &origin){
    command = origin.command;
    objectType = origin.objectType;
    objectID = origin.objectID;
    posX = origin.posX;
    posY = origin.posY;
    return *this;
}

Event::Event(int command):
    command(command),
    objectType(-5),
    objectID(-5),
    posX(-5),
    posY(-5)
{}
