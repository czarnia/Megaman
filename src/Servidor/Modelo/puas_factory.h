#ifndef PUAS_FACTORY_H
#define PUAS_FACTORY_H

#include "ubicable_factory.h"
#include "juego.h"
#include <map>

class Puas_factory : public Ubicable_factory{
	public:
		//Crea un megaman factory.
		Puas_factory(Cargador_mapa *cargador, Juego* juego);
		//Dado un mapa y una coordenada, crea a un Puas.
		virtual Ubicable* crear(Mapa* mapa);
};

#endif //PUAS_FACTORY_H
