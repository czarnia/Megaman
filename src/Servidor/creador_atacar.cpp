#include "creador_atacar.h"

Evento* Creador_atacar::crear(int id, int parametro){
  Evento* e = new Evento_atacar(id, parametro);
  return e;
}
