#include "met_factory.h"
#include "observador_ubicable.h"
#include "observador_personaje.h"
#include "arma_factory.h"
#include "met.h"

Met_factory::Met_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego),
fact_obs(juego){
	creados = 0;
}

//TODO: ACA PODEMOS LEVANTAR LOS DATOS DEL MET DEL XML/JSON
//VELOCIDAD, ETC...
//TODO: ACA SE PEDIRAN LAS COORDENADAS INICIALES AL MAPA.
//TODO: GUARDAR LOS OBJETOS CREADOS CON NEW PARA SU DESTRUCCION.
Ubicable* Met_factory::crear(Mapa* mapa){
	Coordenada coord(-1, -1);
	
	//Creacion del met:
	int id = creados;
	ArmaFactory arma_fact(juego);
	Arma_minion *arma = arma_fact.crear_arma_minion();
	Met *met = new Met(mapa, coord, arma, id);
	//Se agregan los observadores:
	//observador de ubicable:
	fact_obs.crear(met); 
	//observador de personaje:
	Observador_personaje *obs = new Observador_personaje(juego);
	met->agregar_observador(obs);
	//Se agrega el personaje al mapa:
	mapa->agregar_personaje(met);
	//Notifico a los observadores de la creacion del personaje:
	met->notificar_observadores();
	creados++;
	return met;
}
