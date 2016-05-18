#ifndef ATACABLE_H
#define ATACABLE_H

//#include "bala.h"

class Atacable{
  public:
    virtual void recibir_ataque(/*Bala ataque*/) = 0;
    virtual ~Atacable() {}
};

#endif //ATACABLE_H
