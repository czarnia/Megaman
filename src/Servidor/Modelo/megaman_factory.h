#ifndef MEGAMAN_FACTORY_H
#define MEGAMAN_FACTORY_H

#include "ubicable_factory.h"
#include "factory_observador_ubicable.h"
#include "../../Editor/cargador_mapa.h"
#include "juego.h"
#include <map>

class Juego;
class Ubicable_factory;
class Megaman;
class Personaje;

class Megaman_factory : public Ubicable_factory{
	private:
		Factory_observador_ubicable fact_obs;
		std::vector<Megaman*> creados;
		//std::multimap<Megaman*, Observador*> creados;
	public:
		//Dados un puntero a un juego y un puntero a un cargador de
		//mapas, crea un megaman factory.
		Megaman_factory(Cargador_mapa * cargador, Juego *juego);
		//Dado un mapa, crea a un personaje.
		void crear(Mapa* mapa);
};

#endif //MEGAMAN_FACTORY_H
