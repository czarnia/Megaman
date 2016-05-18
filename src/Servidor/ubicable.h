#ifndef UBICABLE_H
#define UBICABLE_H

#include "celda.h"

class Ubicable{
  public:
    //Ubica a un atacable en una celda.
    virtual void ubicar(Celda posicion) = 0;
    //Destructor del ubicable.
    virtual ~Ubicable() {}
};

#endif //UBICABLE_H
