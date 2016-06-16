#ifndef SNIPPER_FACTORY_H
#define SNIPPER_FACTORY_H

#include "ubicable_factory.h"
#include "factory_observador_ubicable.h"
#include "juego.h"
#include <map>

class Snipper_factory : public Ubicable_factory{
	public:
		//Crea un snipper factory.
		Snipper_factory(Cargador_mapa *cargador, Juego *juego);
		//Dado un mapa y una coordenada, crea a un snipper y lo ubica en el mapa.
		void crear(Mapa* mapa);
};

#endif //SNIPPER_FACTORY_H
