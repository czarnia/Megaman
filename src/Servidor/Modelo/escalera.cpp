#include "escalera.h"
#include "personaje.h"
#include "bala.h"
#include "puas.h"
#include "puas_asesinas.h"
#include "bloque.h"
#define TIPO_ESCALERA 2

Escalera::Escalera(Coordenada c) : Elemento(c, TIPO_ESCALERA) {}

bool Escalera::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Escalera::puede_ocupar(Personaje* pj){
	return true;
}

bool Escalera::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Escalera::puede_ocupar(Bala* bala){
	return true;
}

bool Escalera::puede_ocupar(Escalera* esc){
	return false;
}

bool Escalera::puede_ocupar(Bloque* bloque){
	return false;
}

bool Escalera::puede_ocupar(Puas* puas){
	return false;
}

bool Escalera::puede_ocupar(Puas_asesinas* puas){
	return false;
}

void Escalera::interactuar(Personaje* pj){
}

std::vector<Coordenada> Escalera::coordenadas(){
	std::vector<Coordenada> c;
	return c;
}

std::vector<Coordenada> Escalera::coordenadas(Coordenada c){
	std::vector<Coordenada> v;
	return v;
}

Escalera::~Escalera() {}
