#ifndef ARMA_MET_H
#define ARMA_MET_H

#include "arma.h"

class Arma_met : public Arma{
  public:
	Arma_met(Factory_observador_ubicable *fact_ubicables);
    //Ataca, es decir, crea una bala normal.
    virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
    //Destructor de la arma.
    virtual ~Arma_met();
};

#endif //ARMA_MET_H
