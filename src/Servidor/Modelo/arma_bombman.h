#ifndef ARMA_BOMBMAN_H
#define ARMA_BOMBMAN_H

#include "arma_boss.h"

class Arma_bombman : public Arma_boss{
	private:
		int nuevo_id_bala();
		bool equipo_pc;
	public:
		//Dado un Factory_observador_ubicable*, crea una arma bombman.
		Arma_bombman(int id, Factory_observador_ubicable *fact_ubicables);
		//Ataca, es decir, crea una bala normal.
		virtual Bala* atacar(int dir_x, int dir_y, Coordenada c);
		//Destructor de la arma.
		virtual ~Arma_bombman();
};

#endif //ARMA_BOMBMAN_H
