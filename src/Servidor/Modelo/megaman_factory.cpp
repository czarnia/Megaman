#include "megaman_factory.h"
#include <sstream>
#include <iostream>
#include "observador_ubicable.h"
#include "observador_personaje.h"
#include "arma_factory.h"
#include "megaman.h"

MegamanFactory::MegamanFactory(Juego *juego):
juego(juego),
fact_obs(juego){
	creados = 0;
}
//TODO: ACA PODEMOS LEVANTAR LOS DATOS DEL MEGAMAN DEL XML/JSON
//VELOCIDAD, ETC...
//TODO: ACA SE PEDIRAN LAS COORDENADAS INICIALES AL MAPA.
//TODO: GUARDAR LOS OBJETOS CREADOS CON NEW PARA SU DESTRUCCION.
Ubicable* MegamanFactory::crear(Mapa* mapa, Coordenada coord){
	//Creacion del megaman:
	int id = creados;
	ArmaFactory arma_fact(juego);
	Arma_megaman *arma = arma_fact.crear_arma_megaman();
	Megaman *megaman = new Megaman(mapa, coord, arma, id+1);
	//Se agregan los observadores:
	//observador de ubicable:
	fact_obs.crear(megaman);
	//observador de personaje:
	Observador_personaje *obs = new Observador_personaje(juego);
	megaman->agregar_observador(obs);
	//Se agrega el personaje al mapa:
	mapa->agregar_personaje(megaman);
	//Notifico a los observadores de la creacion del personaje:
	megaman->notificar_observadores();
	creados++;
	return megaman;
}

