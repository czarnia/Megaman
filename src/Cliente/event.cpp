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

Event::Event(int command):
    command(command),
    objectType(-5),
    objectID(-5),
    posX(-5),
    posY(-5)
{}
