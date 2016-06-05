#include "megaman_factory.h"
#include <sstream>
#include <iostream>
#include "observador_ubicable.h"
#include "observador_personaje.h"
#include "megaman.h"

MegamanFactory::MegamanFactory(Juego *juego):
juego(juego){
	creados = 0;
}

Personaje* MegamanFactory::crear(Mapa* mapa){
	int x = 3; 
	int y = 6;
	Coordenada coord(x, y); //LAS COORDENADAS INICIALES SE OBTIENEN DE UN ARCHIVO Y SE PIDEN AL MAPA...
	Observador_personaje *obs = new Observador_personaje(juego);
	Observador_ubicable *obs_ubicable = new Observador_ubicable(juego, &coord);
	int id = (creados + 1);
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Megaman *megaman = new Megaman(mapa, coord, id, fact_obs);
	megaman->agregar_observador(obs);
	megaman->agregar_observador(obs_ubicable);
	//megaman->agregar_observador(this);
	mapa->agregar_personaje(megaman);
	creados++;
	//creados.insert(std::pair<Megaman*, Observador*>(megaman, obs));
	//creados.insert(std::pair<Megaman*, Observador*>(megaman, obs_ubicable));
	//ACA PODEMOS LEVANTAR LOS DATOS DEL MEGAMAN DEL XML/JSON
	//VELOCIDAD, ETC...
	return megaman;
}

/*void MegamanFactory::update(Observable *observado){
	Megaman *megaman = (Megaman*)observado;
	if (!megaman->esta_vivo()){
		//delete megamans!
		//delete observadores!
	}
}*/
