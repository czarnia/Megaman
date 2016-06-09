#include "arma_megaman.h"
#include "bala_normal.h"
#include "factory_observador_ubicable.h"

#define SHIFT_RIGHT 100

Arma_megaman::Arma_megaman(int id,
Factory_observador_ubicable *fact_ubicables):
Arma(id, fact_ubicables){
	balas_creadas = 0;
}

Bala* Arma_megaman::atacar(int dir_x, int dir_y, Coordenada c) {
	//Creo una bala:
	int id_bala = id*SHIFT_RIGHT + balas_creadas;
	Bala *bullet = new Bala_normal(dir_x, dir_y, c, id_bala);
	//Se agrega un observador a la bala:
	fact_ubicables->crear(bullet); 
	balas_creadas++;
	return bullet;
}

Arma_megaman::~Arma_megaman() {}
