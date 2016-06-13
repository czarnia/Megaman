#include "escalera_factory.h"
#include "escalera.h"

Escalera_factory::Escalera_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego) {}

Ubicable* Escalera_factory::crear(Mapa* mapa){
	Coordenada coord(-1, -1);
  Escalera* escalera = new Escalera(coord);
  return escalera;
}
