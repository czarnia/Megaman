#ifndef ARMA_MEGAMAN_H
#define ARMA_MEGAMAN_H

#include "arma.h"

class Arma_megaman : public Arma{
  public:
    //Dado un Factory_observador_ubicable*, crea una arma megaman.
	  Arma_megaman(int id, Factory_observador_ubicable *fact_ubicables);
    //Ataca, es decir, crea una bala normal.
    virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
    //Destructor de la arma.
    virtual ~Arma_megaman();
};

#endif //ARMA_MEGAMAN_H
