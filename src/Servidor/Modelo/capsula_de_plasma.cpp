#include "capsula_de_plasma.h"

#define TIPO_CAPSULA_CHICA 16

Capsula_de_plasma::Capsula_de_plasma(Coordenada coord, int tipo_capsula):
Premio(coord, tipo_capsula){}

void Capsula_de_plasma::interactuar(Personaje *pj){
	//if (tipo == TIPO_CAPSULA_CHICA){
	//	pj->ganar_plasma(20);
  //}
	//pj->ganar_plasma(60);
}

Capsula_de_plasma::~Capsula_de_plasma(){}
