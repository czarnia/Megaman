#include "megaman_factory.h"
#include <sstream>
#include <iostream>
#include "observador_ubicable.h"
#include "observador_personaje.h"
#include "arma_factory.h"
#include "megaman.h"

Megaman_factory::Megaman_factory(Cargador_mapa * cargador, Juego *juego):
Ubicable_factory(cargador, juego),
fact_obs(juego){}

void Megaman_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coordenada_megaman = cargador->get_coordenada_megamans();
	if (coordenada_megaman.size() < 1){
		return;
	}
	Coordenada *coord = coordenada_megaman[0];
	int cantidad_jugadores = juego->get_cantidad_jugadores();
	
	if (!juego->inicio_partida()){
		for (int i = 0; i < cantidad_jugadores; i++){
			//Creacion del megaman:
			ArmaFactory arma_fact(juego);
			Arma_megaman *arma = arma_fact.crear_arma_megaman();
			Megaman *megaman = new Megaman(mapa, *coord, arma, i+1);
			creados.push_back(megaman);
			//Se agregan los observadores:
			//observador de ubicable:
			fact_obs.crear(megaman);
		}
	}
	for (unsigned int j = 0; j < creados.size(); j++){
		Megaman *megaman = creados[j];
		if (!megaman->esta_vivo()){
			//delete megaman;
			continue;
		}
		//observador de personaje:
		Observador_personaje *obs = new Observador_personaje(juego);
		megaman->agregar_observador(obs);
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(megaman);
	}
}
