#include "bloque.h"
#include "personaje.h"

bool Bloque::puede_ocupar(Personaje* pj){
	return false;
}

void Bloque::interactuar(Personaje *pj){} //Los bloques no interactuan!

Bloque::~Bloque() {}
