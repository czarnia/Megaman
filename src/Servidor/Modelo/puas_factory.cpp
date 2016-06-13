#include "puas_factory.h"
#include "puas.h"

Puas_factory::Puas_factory(Cargador_mapa *cargador, Juego* juego):
Ubicable_factory(cargador, juego) {}

Ubicable* Puas_factory::crear(Mapa* mapa){
	Coordenada coord(-1, -1);
  Puas* puas = new Puas(coord);
  return puas;
}
