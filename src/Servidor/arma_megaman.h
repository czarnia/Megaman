#ifndef ARMA_MEGAMAN_H
#define ARMA_MEGAMAN_H

#include "arma.h"

class Arma_megaman : public Arma{
  public:
    //Ataca, es decir, crea una bala normal.
    virtual Bala* atacar();
    //Destructor de la arma.
    virtual ~Arma_megaman();
};

#endif //ARMA_MEGAMAN_H
