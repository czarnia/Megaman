#include "creador_parar.h"
#include "evento_parar.h"
#include <string>
#include <iostream>

Creador_parar::Creador_parar(int id_creador) : id(id_creador){}

Creador_parar::~Creador_parar() {}

Evento* Creador_parar::crear(int parametro){
  Evento_parar* e = new Evento_parar(id, parametro);
  return e;
}
