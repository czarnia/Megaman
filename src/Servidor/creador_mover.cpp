#include "creador_mover.h"
#include "evento_mover.h"

Creador_mover::Creador_mover(int id_creador) : id(id_creador){}

Creador_mover::~Creador_mover() {}

Evento* Creador_mover::crear(int parametro){
  Evento_mover* e = new Evento_mover(id, parametro);
  return e;
}
