#include "bloque_factory.h"
#include "bloque.h"

Bloque_factory::Bloque_factory() {}

Ubicable* Bloque_factory::crear(Mapa* mapa, Coordenada coord){
  Bloque* bloque = new Bloque(coord);
  return bloque;
}
