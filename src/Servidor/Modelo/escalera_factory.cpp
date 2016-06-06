#include "escalera_factory.h"
#include "escalera.h"

Escalera_factory::Escalera_factory() {}

Ubicable* Escalera_factory::crear(Mapa* mapa, Coordenada coord){
  Escalera* escalera = new Escalera(coord);
  return escalera;
}
