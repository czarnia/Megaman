#include "met_factory.h"
#include "../Servidor/Modelo/observador_ubicable.h"
#include "../Servidor/Modelo/observador_personaje.h"
#include "../Servidor/Modelo/met.h"

Met_factory::Met_factory(Juego *juego):
juego(juego){
	creados = 0;
}

Ubicable* Met_factory::crear(Mapa* mapa, Coordenada coord){
	Observador_personaje *obs = new Observador_personaje(juego);
	Observador_ubicable *obs_ubicable = new Observador_ubicable(juego, &coord);
	int id = (creados + 1);
	Met *met = new Met(mapa, coord, id);
	met->agregar_observador(obs);
	met->agregar_observador(obs_ubicable);
	mapa->agregar_personaje(met);
	creados++;
	return met;
}
