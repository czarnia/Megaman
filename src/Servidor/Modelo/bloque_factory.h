#ifndef BLOQUE_FACTORY_H
#define BLOQUE_FACTORY_H

#include "ubicable_factory.h"
#include "juego.h"
#include <map>

class Bloque_factory : public Ubicable_factory{
	public:
		//Crea un megaman factory.
		Bloque_factory(Cargador_mapa *cargador, Juego *juego);
		//Dado un mapa y una coordenada, crea a un Bloque.
		virtual Ubicable* crear(Mapa* mapa);
};

#endif //BLOQUE_FACTORY_H
