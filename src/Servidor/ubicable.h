#ifndef UBICABLE_H
#define UBICABLE_H

//#include "celda.h"

class Ubicable{
  public:
    virtual void ubicar(/*Celda posicion*/) = 0;
    virtual ~Ubicable() {}
};

#endif //UBICABLE_H
