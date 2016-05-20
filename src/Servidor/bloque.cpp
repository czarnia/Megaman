#include "bloque.h"

Bloque::Bloque(Coordenada &coordenada){
	coord = coordenada;
}

bool Bloque::puede_ocupar(Personaje* pj){
	return false;
}

Bloque::~Bloque() {}
