#include "puas.h"
#include "personaje.h"

bool Puas::puede_ocupar(Ubicable* ubic){
	return true;
}

void Puas::interactuar(Personaje *pj){
	pj->perder_vida();
}

std::vector<Coordenada> Puas::coordenadas(Coordenada c){
	std::vector<Coordenada> v;
	return v;
}

std::vector<Coordenada> Puas::coordenadas(){
	return coordenadas(coord);
}

Puas::~Puas() {}
