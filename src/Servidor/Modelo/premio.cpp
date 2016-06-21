#include "premio.h"

Premio::Premio(Coordenada coord, int tipo):
Elemento(coord, tipo){}

bool Premio::puede_ocupar(Personaje* pj){
	return true;
}

bool Premio::puede_ocupar(Elemento* elem){
	return true;
}

bool Premio::puede_ocupar(Bala* bala){
	return true;
}

bool Premio::puede_ocupar(Escalera* esc){
	return true;
}

bool Premio::puede_ocupar(Bloque* bloque){
	return false;
}

bool Premio::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Premio::puede_ocupar(Premio* premio){
	return false;
}

bool Premio::puede_ocupar(Puas* puas){
	return false;
}

bool Premio::es_piso(){
	return false;
}

bool Premio::recibe_danio(Bala* ataque){
	return false;
}
