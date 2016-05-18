#ifndef ATACABLE_H
#define ATACABLE_H

//#include "bala.h"

class Atacable{
  public:
    //Hace que un atacable reciba un ataque, dada una bala.
    virtual void recibir_ataque(/*Bala ataque*/) = 0;
    //Destructor del atacable.
    virtual ~Atacable() {}
};

#endif //ATACABLE_H
