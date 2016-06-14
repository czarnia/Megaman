#include "snipper_factory.h"
#include "observador_personaje.h"
#include "observador_ubicable.h"
#include "arma_minion.h"
#include "arma_factory.h"
#include "snipper.h"
#include "jumping_snipper.h"

Snipper_factory::Snipper_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego),
fact_obs(juego){}

void Snipper_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coords_snippers = cargador->get_coordenadas_snippers();
	std::vector<Coordenada*> coords_j_snippers = cargador->get_coordenadas_j_snippers();
	
	for (unsigned int i = 0; i < coords_snippers.size(); i++){
		Coordenada* coord = coords_snippers[i];
		//Creacion del snipper:
		ArmaFactory arma_fact(juego);
		Arma_minion *arma = arma_fact.crear_arma_minion();
		Snipper *snipper = new Snipper(mapa, *coord, arma, i);
		//Se agregan los observadores:
		//observador de ubicable:
		fact_obs.crear(snipper); 
		//observador de personaje:
		Observador_personaje *obs = new Observador_personaje(juego);
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
		//Se agregan los observadores:
		//observador de ubicable:
		fact_obs.crear(jsnipper); 
		//observador de personaje:
		Observador_personaje *obs = new Observador_personaje(juego);
		jsnipper->agregar_observador(obs);
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(jsnipper);
	} 
	
}


