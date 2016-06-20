#include "arma_magnetman.h"
#include "factory_observador_ubicable.h"
#include "bala_magnetman.h"
#include <stdlib.h>
#include <sstream>

#define TIPO_ARMA_MAGNETMAN 41

Arma_magnetman::Arma_magnetman(int id,
Factory_observador_ubicable *fact_ubicables):
Arma_boss(TIPO_ARMA_MAGNETMAN, id, fact_ubicables){
	balas_creadas = 0;
	equipo_pc = false;
}

int Arma_magnetman::nuevo_id_bala(){
	std::stringstream converter;
	converter << this->id << this->tipo << balas_creadas;
	std::string id_bala = converter.str();
	int id_unico = atoi(id_bala.c_str());
	return id_unico;
}

Bala* Arma_magnetman::atacar(int dir_x, int dir_y, Coordenada c) {
	//Creo una bala:
	int id_bala = nuevo_id_bala();
	Bala_especial *bullet = new Bala_magnetman(dir_x, dir_y, c, id_bala);
	if (equipo_pc){
		bullet->cambiar_enemigo();
	}
	//Se agrega un observador a la bala:
	fact_ubicables->crear(bullet);
	balas_creadas++;
	return bullet;
}

Arma_magnetman::~Arma_magnetman() {}
