#include "puas.h"

bool Puas::puede_ocupar(Personaje* pj){
	return true;
}

void Puas::interactuar(Mapa &mapa, Personaje *pj){
	pj->perder_vida();
}

Puas::~Puas() {}
