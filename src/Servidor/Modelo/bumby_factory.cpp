#include "bumby_factory.h"
#include "observador_personaje_npc.h"
#include "observador_ubicable.h"
#include "arma_minion.h"
#include "arma_factory.h"
#include "bumby.h"

Bumby_factory::Bumby_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego){}

void Bumby_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coords_bumbys = cargador->get_coordenadas_bumby();

	for (unsigned int i = 0; i < coords_bumbys.size(); i++){
		Coordenada* coord = coords_bumbys[i];
		//Creacion del bumby:
		ArmaFactory arma_fact(juego);
		Arma_minion *arma = arma_fact.crear_arma_minion();
		Bumby *bumby = new Bumby(mapa, *coord, arma, i);
		//observador de personaje:
		Observador_personaje_npc *obs = new Observador_personaje_npc(juego, bumby);
		bumby->agregar_observador(obs);
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(bumby);
	}
}
