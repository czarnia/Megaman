#include "puas_asesinas.h"
#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas.h"
#include "bloque.h"

bool Puas_asesinas::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Puas_asesinas::puede_ocupar(Personaje* pj){
	return true;
}

bool Puas_asesinas::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Puas_asesinas::puede_ocupar(Bala* bala){
	return true;
}

bool Puas_asesinas::puede_ocupar(Escalera* esc){
	return true;
}

bool Puas_asesinas::puede_ocupar(Bloque* bloque){
	return false;
}

bool Puas_asesinas::puede_ocupar(Puas* puas){
	return false;
}

bool Puas_asesinas::puede_ocupar(Puas_asesinas* puas){
	return false;
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
