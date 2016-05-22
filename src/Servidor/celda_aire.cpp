#include "celda_aire.h"
#include <stdio.h>
#include <stdlib.h>
#include <map>

Celda_aire::Celda_aire(size_t x, size_t y, Elemento* obstaculo):
Celda(x, y){
	elem = obstaculo;
}

void Celda_aire::agregar_personaje(Personaje* ocupa){
	ocupantes[ocupa->devolver_id()] = ocupa;
}

void Celda_aire::quitar_personaje(Personaje* ocupa){
	ocupantes.erase(ocupa->devolver_id());
}

bool Celda_aire::puedo_ubicar(){
	return true;
}

Celda_aire::~Celda_aire() {}
