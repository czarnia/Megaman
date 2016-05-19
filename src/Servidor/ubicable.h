#ifndef UBICABLE_H
#define UBICABLE_H

#include "mapa.h"

class Ubicable{
  public:
    //Intenta ubicar a un elemento ubicable en las coordenadas del mapa
    //que sean ocupadas por ese objeto, devuelve true sólo si la ubicación
    //del objeto o personaje fue realizada con éxito. 
    virtual bool ubicar(Mapa &mapa) = 0;
    //Destructor del ubicable.
    virtual ~Ubicable() {}
};

#endif //UBICABLE_H
