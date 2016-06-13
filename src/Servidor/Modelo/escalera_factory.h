#ifndef ESCALERA_FACTORY_H
#define ESCALERA_FACTORY_H

#include "ubicable_factory.h"
#include "juego.h"
#include "../../Editor/cargador_mapa.h"
#include <map>

class Escalera_factory : public Ubicable_factory{
	public:
		//Crea una factory de escaleras.
		Escalera_factory(Cargador_mapa *cargador, Juego *juego);
		//Dado un mapa, ubica las escaleras en el mapa.
		virtual Ubicable* crear(Mapa* mapa);
};

#endif //ESCALERA_FACTORY_H
