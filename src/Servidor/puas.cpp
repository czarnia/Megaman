#include "puas.h"
#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas_asesinas.h"
#include "bloque.h"

bool Puas::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Puas::puede_ocupar(Personaje* pj){
	return true;
}

bool Puas::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Puas::puede_ocupar(Bala* bala){
	return true;
}

bool Puas::puede_ocupar(Escalera* esc){
	return true;
}

bool Puas::puede_ocupar(Bloque* bloque){
	return false;
}

bool Puas::puede_ocupar(Puas* puas){
	return false;
}

bool Puas::puede_ocupar(Puas_asesinas* puas){
	return false;
}

void Puas::interactuar(Personaje *pj){
	return pj->perder_vida();
}

std::vector<Coordenada> Puas::coordenadas(Coordenada c){
	std::vector<Coordenada> v;
	return v;
}

std::vector<Coordenada> Puas::coordenadas(){
	return coordenadas(coord);
}

Puas::~Puas() {}
