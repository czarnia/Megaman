#include "creador_atacar.h"
#include "evento_atacar.h"

Creador_atacar::Creador_atacar(int id_creador) : id(id_creador) {}

Creador_atacar::~Creador_atacar() {}

Evento* Creador_atacar::crear(int parametro){
  Evento_atacar* e = new Evento_atacar(id, parametro);
  return e;
}
