#ifndef ARMA_MAGNETMAN_H
#define ARMA_MAGNETMAN_H

#include "arma_boss.h"

class Arma_magnetman : public Arma_boss{
	private:
		int nuevo_id_bala();
	public:
		//Dado un Factory_observador_ubicable*, crea una arma magnetman.
		Arma_magnetman(int id, Factory_observador_ubicable *fact_ubicables);
		//Crea una bala magnetman.
		virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
		//Destructor de la arma.
		virtual ~Arma_magnetman();
};

#endif //ARMA_MAGNETMAN_H
