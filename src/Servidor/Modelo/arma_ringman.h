#ifndef ARMA_RINGMAN_H
#define ARMA_RINGMAN_H

#include "arma.h"

class Arma_ringman : public Arma{
	private:
		int nuevo_id_bala();
	public:
		//Dado un Factory_observador_ubicable*, crea una arma ringman.
		Arma_ringman(int id, Factory_observador_ubicable *fact_ubicables);
		//Ataca, es decir, crea una bala normal.
		virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
		//Destructor de la arma.
		virtual ~Arma_ringman();
};

#endif //ARMA_RINGMAN_H
