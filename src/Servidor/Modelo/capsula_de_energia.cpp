#include "capsula_de_energia.h"

#define TIPO_CAPSULA_CHICA 14

Capsula_de_energia::Capsula_de_energia(Coordenada coord, int tipo_capsula):
Premio(coord, tipo_capsula){}

void Capsula_de_energia::interactuar(Personaje *pj){
	if (tipo == TIPO_CAPSULA_CHICA){
		pj->ganar_energia(20);
	}
	pj->ganar_energia(60);
}

Capsula_de_energia::~Capsula_de_energia(){}
