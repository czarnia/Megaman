#include "met_factory.h"
#include "observador_ubicable.h"
#include "observador_personaje.h"
#include "arma_factory.h"
#include "met.h"

Met_factory::Met_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego){}

//TODO: ACA PODEMOS LEVANTAR LOS DATOS DEL MET DEL XML/JSON
//VELOCIDAD, ETC...
//TODO: ACA SE PEDIRAN LAS COORDENADAS INICIALES AL MAPA.
//TODO: GUARDAR LOS OBJETOS CREADOS CON NEW PARA SU DESTRUCCION.
void Met_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coords_mets = cargador->get_coordenadas_mets();
	
	for (unsigned int i = 0; i < coords_mets.size(); i++){
		Coordenada *coord = coords_mets[i];
		//Creacion del met:
		ArmaFactory arma_fact(juego);
		Arma_minion *arma = arma_fact.crear_arma_minion();
		Met *met = new Met(mapa, *coord, arma, i);
		//observador de personaje:
		Observador_personaje *obs = new Observador_personaje(juego, *coord);
		met->agregar_observador(obs);
		//Se agrega el personaje al mapa:
		mapa->agregar_personaje(met);
	} 
}
