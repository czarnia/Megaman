#include "megaman_factory.h"
#include <sstream>
#include <iostream>
#include "observador_personaje_pc.h"
#include "arma_factory.h"
#include "megaman.h"

Megaman_factory::Megaman_factory(Cargador_mapa * cargador, Juego *juego):
Ubicable_factory(cargador, juego){}

void Megaman_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coordenada_megaman = cargador->get_coordenada_megamans();
	if (coordenada_megaman.size() < 1){
		return;
	}
	Coordenada *coord = coordenada_megaman[0];
	Observador_personaje_pc::set_coordenada_respawn(*coord);
	int cantidad_jugadores = juego->get_cantidad_jugadores();

	if (!juego->inicio_partida()){
		for (int i = 0; i < cantidad_jugadores; i++){
			//Creacion del megaman:
			ArmaFactory arma_fact(juego);
			Arma_megaman *arma = arma_fact.crear_arma_megaman();
			Megaman *megaman = new Megaman(mapa, *coord, arma, i+1);
			creados.push_back(megaman);
			//observador de personaje:
			Observador_personaje_pc *obs = new Observador_personaje_pc(juego, megaman);
			megaman->agregar_observador(obs);
		}
	}
	for (unsigned int j = 0; j < creados.size(); j++){
		Megaman *megaman = creados[j];
		if (!megaman->esta_vivo()){
			//delete megaman;
			continue;
		}
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(megaman);
	}
}
