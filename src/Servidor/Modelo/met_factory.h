#ifndef MET_FACTORY_H
#define MET_FACTORY_H

#include "ubicable_factory.h"
#include "juego.h"
#include <map>

class Met_factory : public Ubicable_factory{
	private:
		Juego* juego;
		int creados;
	public:
		//Dado un puntero a un juego, crea un megaman factory.
		Met_factory(Juego *juego);
		//Dado un mapa y una coordenada, crea a un met.
		virtual Ubicable* crear(Mapa* mapa, Coordenada coord);
};

#endif //MET_FACTORY_H
