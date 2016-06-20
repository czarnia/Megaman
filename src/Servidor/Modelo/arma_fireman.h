#ifndef ARMA_FIREMAN_H
#define ARMA_FIREMAN_H

#include "arma_boss.h"

class Arma_fireman : public Arma_boss{
	private:
		int nuevo_id_bala();
	public:
		//Dado un Factory_observador_ubicable*, crea una arma fireman.
		Arma_fireman(int id, Factory_observador_ubicable *fact_ubicables);
		//Ataca, es decir, crea una bala normal.
		virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
		//Destructor de la arma.
		virtual ~Arma_fireman();
};

#endif //ARMA_FIREMAN_H
