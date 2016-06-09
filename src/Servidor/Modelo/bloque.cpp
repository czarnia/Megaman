#include "bloque.h"
#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas.h"
#include <algorithm>
#include <vector>
#define ALTO 2
#define ANCHO 2
#define TIPO_BLOQUE 10

Bloque::Bloque(Coordenada c) : Elemento(c, TIPO_BLOQUE) {
	alto = ALTO;
	ancho = ANCHO;
}

bool Bloque::puede_ocupar(Personaje* pj){
	return false;
}

bool Bloque::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Bloque::puede_ocupar(Bloque* bloque){
	return false;
}

bool Bloque::puede_ocupar(Bala* bala){
	return false;
}

bool Bloque::puede_ocupar(Escalera* esc){
	return false;
}

bool Bloque::puede_ocupar(Puas* puas){
	return false;
}

void Bloque::interactuar(Personaje *pj){} //Los bloques no interactuan!

Bloque::~Bloque(){}
