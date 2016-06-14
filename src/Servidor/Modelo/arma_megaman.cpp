#include "arma_megaman.h"
#include "bala_normal.h"
#include "factory_observador_ubicable.h"
#include <stdlib.h>
#include <sstream>

#define TIPO_ARMA_MEGAMAN 30

Arma_megaman::Arma_megaman(int id,
Factory_observador_ubicable *fact_ubicables):
Arma(TIPO_ARMA_MEGAMAN, id, fact_ubicables){
	balas_creadas = 0;
}

int Arma_megaman::nuevo_id_bala(){
	std::stringstream converter;
	converter << this->id << this->tipo << balas_creadas;
	std::string id_bala = converter.str();
	int id_unico = atoi(id_bala.c_str());
	return id_unico;
}

Bala* Arma_megaman::atacar(int dir_x, int dir_y, Coordenada c) {
	//Creo una bala:
	int id_bala = nuevo_id_bala();
	Bala *bullet = new Bala_normal(dir_x, dir_y, c, id_bala);
	//Se agrega un observador a la bala:
	fact_ubicables->crear(bullet); 
	balas_creadas++;
	return bullet;
}

Arma_megaman::~Arma_megaman() {}
