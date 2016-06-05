#include "factory_observador_ubicable.h"

Factory_observador_ubicable::Factory_observador_ubicable(Juego *j):
juego(j){}

void Factory_observador_ubicable::crear(Ubicable *obs){
	Coordenada *coord = new Coordenada(obs->get_coordenada().obtener_abscisa(), //CAMBIAR ESTE GET PARA QUE DEVUELVA PUNTERO!!!
	obs->get_coordenada().obtener_ordenada());
	Observador_ubicable *observador = new Observador_ubicable(juego, coord);
	creados.push_back(observador);
	obs->agregar_observador(observador);
}

Factory_observador_ubicable::~Factory_observador_ubicable(){}

