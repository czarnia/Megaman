#include "creador_mover.h"

Evento* Creador_mover::crear(int id, int parametro){
  Evento* e = new Evento_mover(id, parametro);
  return e;
}
