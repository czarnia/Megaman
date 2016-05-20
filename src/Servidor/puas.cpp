#include "puas.h"

Puas::Puas(Coordenada &coordenada){
	coord = coordenada;
}

bool Puas::puede_ocupar(Personaje* pj){
	return true;
}

Puas::~Puas() {}
