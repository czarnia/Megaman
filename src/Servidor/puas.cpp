#include "puas.h"
#include "personaje.h"

bool Puas::puede_ocupar(Personaje* pj){
	return true;
}

void Puas::interactuar(Personaje *pj){
	pj->perder_vida();
}

Puas::~Puas() {}
