#include "puas.h"

bool Puas::puede_ocupar(Personaje* pj){
	return true;
}

void Puas::interactuar(Personaje *pj){
	//COMENTADO POR PROBLEMAS CON REFERENCIAS CIRCULARES:
	//pj->perder_vida();
}

Puas::~Puas() {}
