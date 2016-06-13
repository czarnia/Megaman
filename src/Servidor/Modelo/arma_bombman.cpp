#include "arma_bombman.h"
#include "bala_bombman.h"
#include "factory_observador_ubicable.h"

#define SHIFT_RIGHT 100

Arma_bombman::Arma_bombman(int id,
Factory_observador_ubicable *fact_ubicables):
Arma(id, fact_ubicables){
	balas_creadas = 0;
}

Bala* Arma_bombman::atacar(int dir_x, int dir_y, Coordenada c) {
	//Creo una bala:
	int id_bala = id*SHIFT_RIGHT + balas_creadas;
	Bala *bullet = new Bala_bombman(dir_x, dir_y, c, id_bala);
	//Se agrega un observador a la bala:
	fact_ubicables->crear(bullet);
	balas_creadas++;
	return bullet;
}

Arma_bombman::~Arma_bombman() {}
