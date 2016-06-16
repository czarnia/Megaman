#ifndef BUMBY_FACTORY_H
#define BUMBY_FACTORY_H

#include "ubicable_factory.h"
#include "juego.h"
#include <map>

class Bumby_factory : public Ubicable_factory{
	public:
		//Dados un puntero a un juego y un puntero a un cargador de
		//mapas, crea un un Bumby_factory.
		Bumby_factory(Cargador_mapa *cargador, Juego *juego);
		//Dado un mapa, crea a un personaje.
		void crear(Mapa* mapa);
};

#endif //BUMBY_FACTORY_H
