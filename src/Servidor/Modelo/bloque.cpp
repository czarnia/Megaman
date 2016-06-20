#include "bloque.h"
#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas.h"
#include <algorithm>
#include <vector>

#define ALTO 30
#define ANCHO 30
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

bool Bloque::puede_ocupar(Premio* premio){
	return false;
}

bool Bloque::puede_ocupar(Puas* puas){
	return false;
}

void Bloque::interactuar(Personaje *pj){} //Los bloques no interactuan!

bool Bloque::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Bloque::es_piso(){
	return true;
}

bool Bloque::recibe_danio(Bala* ataque){
	return true; //TRUCHADA PARA QUE NO ATRAVIESE BLOQUES!
}

Bloque::~Bloque(){}
