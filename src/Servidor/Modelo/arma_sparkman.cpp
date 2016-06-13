#include "arma_sparkman.h"
#include "bala_sparkman.h"
#include "factory_observador_ubicable.h"

#define SHIFT_RIGHT 100

Arma_sparkman::Arma_sparkman(int id,
Factory_observador_ubicable *fact_ubicables):
Arma(id, fact_ubicables){
	balas_creadas = 0;
}

Bala* Arma_sparkman::atacar(int dir_x, int dir_y, Coordenada c) {
	//Creo una bala:
	int id_bala = id*SHIFT_RIGHT + balas_creadas;
	Bala *bullet = new Bala_sparkman(dir_x, dir_y, c, id_bala);
	//Se agrega un observador a la bala:
	fact_ubicables->crear(bullet);
	balas_creadas++;
	return bullet;
}

Arma_sparkman::~Arma_sparkman() {}
