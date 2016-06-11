#include "arma_minion.h"
#include "bala_minion.h"

#define SHIFT_RIGHT 100

Arma_minion::Arma_minion(int id,
Factory_observador_ubicable *fact_ubicables):
Arma(id, fact_ubicables){}

Bala* Arma_minion::atacar(int dir_x, int dir_y, Coordenada c) {
	int id_bala = id*SHIFT_RIGHT + balas_creadas;
	Bala *bullet = new Bala_minion(dir_x, dir_y, c, id_bala);
	balas_creadas++;
	return bullet;
}

Arma_minion::~Arma_minion() {}
