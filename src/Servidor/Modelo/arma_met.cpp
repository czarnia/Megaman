#include "arma_met.h"
#include "bala_met.h"

#define SHIFT_RIGHT 100

Arma_met::Arma_met(int id,
Factory_observador_ubicable *fact_ubicables):
Arma(id, fact_ubicables){}

Bala* Arma_met::atacar(int dir_x, int dir_y, Coordenada c) {
	int id_bala = id*SHIFT_RIGHT + balas_creadas;
	Bala *bullet = new Bala_met(dir_x, dir_y, c, id_bala);
	balas_creadas++;
	return bullet;
}

Arma_met::~Arma_met() {}
