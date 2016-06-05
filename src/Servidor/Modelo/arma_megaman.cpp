#include "arma_megaman.h"
#include "bala_normal.h"
#include "factory_observador_ubicable.h"

Arma_megaman::Arma_megaman(Factory_observador_ubicable *fact_ubicables):
Arma(fact_ubicables){
	balas_creadas = 0;
}

Bala* Arma_megaman::atacar(int dir_x, int dir_y, Coordenada c) {
	//Creo una bala:
	Bala *bullet = new Bala_normal(dir_x, dir_y, c, balas_creadas);
	//Se agrega un observador a la bala:
	fact_ubicables->crear(bullet); 
	balas_creadas++;
	return bullet;
}

Arma_megaman::~Arma_megaman() {}
