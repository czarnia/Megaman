#include "bumby_factory.h"
#include "observador_personaje.h"
#include "observador_ubicable.h"
#include "arma_minion.h"
#include "arma_factory.h"
#include "bumby.h"

Bumby_factory::Bumby_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego),
fact_obs(juego){}

void Bumby_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coords_bumbys = cargador->get_coordenadas_bumby();
	
	for (unsigned int i = 0; i < coords_bumbys.size(); i++){
		Coordenada* coord = coords_bumbys[i];
		//Creacion del bumby:
		ArmaFactory arma_fact(juego);
		Arma_minion *arma = arma_fact.crear_arma_minion();
		Bumby *bumby = new Bumby(mapa, *coord, arma, i);
		//Se agregan los observadores:
		//observador de ubicable:
		fact_obs.crear(bumby); 
		//observador de personaje:
		Observador_personaje *obs = new Observador_personaje(juego);
		bumby->agregar_observador(obs);
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(bumby);
	}
}
