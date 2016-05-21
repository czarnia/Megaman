#include "celda_aire.h"
#include <stdio.h>
#include <stdlib.h>
#include <map>

Celda_aire::Celda_aire(Elemento* obstaculo = NULL){
  elem = obstaculo;
}

bool Celda_aire::agregar_personaje(Personaje* ocupa){
  ocupantes[ocupa.devolver_id()] = ocupa;
}

virtual bool Celda_aire::puedo_ubicar(){
  return true;
}

virtual Celda_aire::~Celda_aire() {}
