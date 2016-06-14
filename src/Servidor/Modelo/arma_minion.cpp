#include "arma_minion.h"
#include "bala_minion.h"
#include <stdlib.h>
#include <sstream>

#define TIPO_ARMA_MINION 31

Arma_minion::Arma_minion(int id,
Factory_observador_ubicable *fact_ubicables):
Arma(TIPO_ARMA_MINION, id, fact_ubicables){}

int Arma_minion::nuevo_id_bala(){
	std::stringstream converter;
	converter << this->id << this->tipo << balas_creadas;
	std::string id_bala = converter.str();
	int id_unico = atoi(id_bala.c_str());
	return id_unico;
}


Bala* Arma_minion::atacar(int dir_x, int dir_y, Coordenada c) {
	int id_bala = nuevo_id_bala();
	Bala *bullet = new Bala_minion(dir_x, dir_y, c, id_bala);
	balas_creadas++;
	return bullet;
}

Arma_minion::~Arma_minion() {}
