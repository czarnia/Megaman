#include "bloque.h"
#include "personaje.h"

#define ALTO 2
#define ANCHO 2

bool Bloque::puede_ocupar(Ubicable* ubic){
	return false;
}

void Bloque::interactuar(Personaje *pj){} //Los bloques no interactuan!

std::vector<Coordenada> Bloque::coordenadas(Coordenada c){
	std::vector<Coordenada> v;
	v.push_back(c);
	v.push_back(c.arriba(ALTO/2).izquierda(ANCHO/2));
	v.push_back(c.arriba(ALTO/2).derecha(ANCHO/2));
	v.push_back(c.abajo(ALTO/2).izquierda(ANCHO/2));
	v.push_back(c.abajo(ALTO/2).derecha(ANCHO/2));
	return v;
}

std::vector<Coordenada> Bloque::coordenadas(){
	return coordenadas(coord);
}

Bloque::~Bloque() {}
