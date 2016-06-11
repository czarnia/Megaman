#ifndef ARMA_MINION_H
#define ARMA_MINION_H

#include "arma.h"

class Arma_minion : public Arma{
  public:
    //Dado un Factory_observador_ubicable*, crea una arma minion.
	Arma_minion(int id, Factory_observador_ubicable *fact_ubicables);
    //Ataca, es decir, crea una bala met.
    virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
    //Destructor de la arma.
    virtual ~Arma_minion();
};

#endif //ARMA_MINION_H
