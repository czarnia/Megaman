#ifndef ARMA_H
#define ARMA_H

#include "bala.h"

class Arma{
  public:
    //Ataca, es decir, crea una bala.
    virtual Bala* atacar(int dir_x, int dir_y, Coordenada c) = 0;
    //Destructor de la arma.
    virtual ~Arma() {}
};

#endif //ARMA_H
