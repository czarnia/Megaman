#ifndef ARMA_H
#define ARMA_H

#include "bala.h"

class Arma{
  public:
    //Ataca, es decir, crea una bala.
    virtual Bala* atacar() = 0;
    //Destructor de la arma.
    virtual ~Arma() {}
};

#endif //ARMA_H
