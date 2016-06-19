#include "arma_ringman.h"
#include "factory_observador_ubicable.h"
#include "bala_ringman.h"
#include <stdlib.h>
#include <sstream>

#define TIPO_ARMA_RINGMAN 43

Arma_ringman::Arma_ringman(int id, 
Factory_observador_ubicable *fact_ubicables):
Arma(TIPO_ARMA_RINGMAN, id, fact_ubicables){
	balas_creadas = 0;
}

int Arma_ringman::nuevo_id_bala(){
	std::stringstream converter;
	converter << this->id << this->tipo << balas_creadas;
	std::string id_bala = converter.str();
	int id_unico = atoi(id_bala.c_str());
	return id_unico;
}

Bala* Arma_ringman::atacar(int dir_x, int dir_y, Coordenada c){
	//Creo una bala:
	int id_bala = nuevo_id_bala();
	Bala *bullet = new Bala_ringman(dir_x, dir_y, c, id_bala);
	//Se agrega un observador a la bala:
	fact_ubicables->crear(bullet);
	balas_creadas++;
	return bullet;
}

Arma_ringman::~Arma_ringman(){}
