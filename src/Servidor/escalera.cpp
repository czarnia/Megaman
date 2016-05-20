#include "escalera.h"

Escalera::Escalera(Coordenada &coordenada){
	coord = coordenada;
}

bool Escalera::puede_ocupar(Personaje* pj){
	return true;
}

Escalera::~Escalera() {}
