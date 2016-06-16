#include "snipper_factory.h"
#include "observador_personaje_npc_con_escudo.h"
#include "observador_ubicable.h"
#include "arma_minion.h"
#include "arma_factory.h"
#include "snipper.h"
#include "jumping_snipper.h"

Snipper_factory::Snipper_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego){}

void Snipper_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coords_snippers = cargador->get_coordenadas_snippers();
	std::vector<Coordenada*> coords_j_snippers = cargador->get_coordenadas_j_snippers();

	for (unsigned int i = 0; i < coords_snippers.size(); i++){
		Coordenada* coord = coords_snippers[i];
		//Creacion del snipper:
		ArmaFactory arma_fact(juego);
		Arma_minion *arma = arma_fact.crear_arma_minion();
		Snipper *snipper = new Snipper(mapa, *coord, arma, i);
		//observador de personaje:
		Observador_personaje *obs = new Observador_personaje_npc_con_escudo(juego, snipper);
		snipper->agregar_observador(obs);
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(snipper);
	}
	for (unsigned int i = 0; i < coords_j_snippers.size(); i++){
		Coordenada* coord = coords_j_snippers[i];
		//Creacion del jumping snipper:
		ArmaFactory arma_fact(juego);
		Arma_minion *arma = arma_fact.crear_arma_minion();
		Jumping_snipper *jsnipper = new Jumping_snipper(mapa, *coord, arma, i);
		//observador de personaje:
		Observador_personaje *obs = new Observador_personaje_npc_con_escudo(juego, jsnipper);
		jsnipper->agregar_observador(obs);
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(jsnipper);
	}

}
