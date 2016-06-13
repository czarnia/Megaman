#ifndef ARMA_SPARKMAN_H
#define ARMA_SPARKMAN_H

#include "arma.h"

class Arma_sparkman : public Arma{
  public:
    //Dado un Factory_observador_ubicable*, crea una arma sparkman.
	  Arma_sparkman(int id, Factory_observador_ubicable *fact_ubicables);
    //Ataca, es decir, crea una bala normal.
    virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
    //Destructor de la arma.
    virtual ~Arma_sparkman();
};

#endif //ARMA_SPARKMAN_H
