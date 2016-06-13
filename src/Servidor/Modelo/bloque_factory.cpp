#include "bloque_factory.h"
#include "bloque.h"

Bloque_factory::Bloque_factory(Cargador_mapa *cargador, Juego *juego) :
Ubicable_factory(cargador, juego) {}

Ubicable* Bloque_factory::crear(Mapa* mapa){
	Coordenada coord(-1, -1);
	Bloque* bloque = new Bloque(coord);
	return bloque;
}
