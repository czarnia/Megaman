#include "creador_start.h"
#include "evento_start.h"

Creador_start::Creador_start(int id_creador) : id(id_creador) {}

Creador_start::~Creador_start() {}

Evento_lobby* Creador_start::crear(int parametro){
  Evento_start* e = new Evento_start();
  return e;
}
