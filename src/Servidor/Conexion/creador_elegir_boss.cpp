#include "creador_elegir_boss.h"
#include "evento_elegir_boss.h"

Creador_elegir_boss::Creador_elegir_boss(int id_creador) : id(id_creador) {}

Creador_elegir_boss::~Creador_elegir_boss() {}

Evento_lobby* Creador_elegir_boss::crear(int parametro){
  Evento_elegir_boss* e = new Evento_elegir_boss(parametro);
  return e;
}
