#include "puas.h"
#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "bloque.h"
#define TIPO_PUAS 3

Puas::Puas(Coordenada c) : Elemento(c, TIPO_PUAS) {}

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

bool Puas::puede_ocupar(Puas* Puas){
	return false;
}

bool Puas::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Puas::puede_ocupar(Bloque* bloque){
	return false;
}

bool Puas::puede_ocupar(Premio* premio){
	return false;
}

void Puas::interactuar(Personaje *pj){
	if (this->colisiona(pj)){
		pj->perder_vida();
	}
}

void Puas::notificar_observadores(){}

void Puas::agregar_observador(Observador_ubicable *observador){
	Observable::agregar_observador(observador);
}

void Puas::quitar_observador(Observador_ubicable *observador){
	Observable::agregar_observador(observador);
}

Puas::~Puas() {}
