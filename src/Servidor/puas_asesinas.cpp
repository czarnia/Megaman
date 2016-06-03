#include "puas_asesinas.h"
#include "personaje.h"

bool Puas_asesinas::puede_ocupar(Ubicable* ubic){
	return true;
}

void Puas_asesinas::interactuar(Personaje *pj){
  while (pj->esta_vivo()){
    pj->perder_vida();
  }
}

std::vector<Coordenada> Puas_asesinas::coordenadas(Coordenada c){
	std::vector<Coordenada> v;
	return v;
}

std::vector<Coordenada> Puas_asesinas::coordenadas(){
	return coordenadas(coord);
}

Puas_asesinas::~Puas_asesinas() {}
