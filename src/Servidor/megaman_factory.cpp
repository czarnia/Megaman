#include "megaman_factory.h"
#include "megaman.h"
#include <sstream>

MegamanFactory::MegamanFactory(Juego *juego):
PersonajeFactory(juego){}

Personaje* MegamanFactory::crear(Mapa* mapa){
	int x, y;
	Coordenada coord(x, y); //LAS COORDENADAS INICIALES SE OBTIENEN DE UN ARCHIVO Y SE PIDEN AL MAPA...
	ObservadorPersonaje *obs = new ObservadorPersonaje(juego);
	std::stringstream id("megaman");
	id << creados.size();
	Megaman *megaman = new Megaman(mapa, coord, id.str());
	creados.insert(std::pair<Megaman*, ObservadorPersonaje*>(megaman, obs));
	megaman->agregar_observador(obs);
	megaman->agregar_observador(this);
	mapa->agregar_personaje(megaman);
	//ACA PODEMOS LEVANTAR LOS DATOS DEL MEGAMAN DEL XML/JSON
	//VELOCIDAD, ETC...
}

void MegamanFactory::update(Observable *observado){
	Megaman *megaman = (Megaman*)observado;
	ObservadorPersonaje* obs;
	if (!megaman->esta_vivo()){
		obs = creados[megaman];
		creados.erase(creados.find(megaman));
	}
	delete megaman;
	delete obs;
}
