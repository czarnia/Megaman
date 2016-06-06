#include "puas_factory.h"
#include "puas.h"

Puas_factory::Puas_factory() {}

Ubicable* Puas_factory::crear(Mapa* mapa, Coordenada coord){
  Puas* puas = new Puas(coord);
  return puas;
}
