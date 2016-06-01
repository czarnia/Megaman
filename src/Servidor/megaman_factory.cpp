#include "megaman_factory.h"
#include "megaman.h"
#include <sstream>
#include <iostream>

MegamanFactory::MegamanFactory(Juego *juego):
PersonajeFactory(juego){}

Personaje* MegamanFactory::crear(Mapa* mapa){
	int x = 5; 
	int y = 6;
	Coordenada coord(x, y); //LAS COORDENADAS INICIALES SE OBTIENEN DE UN ARCHIVO Y SE PIDEN AL MAPA...
	ObservadorPersonaje *obs = new ObservadorPersonaje(juego);
	std::stringstream id;
	id << (creados.size() + 1);
	std::string nombre("megaman");
	nombre += id.str();
	Megaman *megaman = new Megaman(mapa, coord, nombre);
	creados.insert(std::pair<Megaman*, ObservadorPersonaje*>(megaman, obs));
	megaman->agregar_observador(obs);
	megaman->agregar_observador(this);
	mapa->agregar_personaje(nombre, megaman);
	//ACA PODEMOS LEVANTAR LOS DATOS DEL MEGAMAN DEL XML/JSON
	//VELOCIDAD, ETC...
	return megaman;
}

void MegamanFactory::update(Observable *observado){
	Megaman *megaman = (Megaman*)observado;
	if (!megaman->esta_vivo()){
		creados.erase(creados.find(megaman));
		delete megaman;
		//delete creados[megaman];
	}
}
