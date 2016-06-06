#include "factory_observador_ubicable.h"

Factory_observador_ubicable::Factory_observador_ubicable(Juego *j):
juego(j){}

void Factory_observador_ubicable::crear(Ubicable *obs){
	Coordenada *coord = new Coordenada(-1, -1);
	Observador_ubicable *observador = new Observador_ubicable(juego, coord);
	creados.push_back(observador);
	obs->agregar_observador(observador);
}

Factory_observador_ubicable::~Factory_observador_ubicable(){}

