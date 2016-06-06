#include "met_factory.h"
#include "../Servidor/Modelo/observador_ubicable.h"
#include "../Servidor/Modelo/observador_personaje.h"
#include "../Servidor/Modelo/met.h"

Met_factory::Met_factory(Juego *juego):
juego(juego){
	creados = 0;
}

Ubicable* Met_factory::crear(Mapa* mapa, Coordenada coord){
	int id = (creados + 1);
	Observador_personaje *obs = new Observador_personaje(juego);
	Observador_ubicable *obs_ubicable = new Observador_ubicable(juego, &coord);
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Met *met = new Met(mapa, coord, id, fact_obs);
	met->agregar_observador(obs);
	met->agregar_observador(obs_ubicable);
	mapa->agregar_personaje(met);
	creados++;
	return met;
}
