#ifndef BUMBY_FACTORY_H
#define BUMBY_FACTORY_H

#include "ubicable_factory.h"
#include "factory_observador_ubicable.h"
#include "juego.h"
#include <map>

class Bumby_factory : public Ubicable_factory{
	private:
		Factory_observador_ubicable fact_obs;
	public:
		Bumby_factory(Cargador_mapa *cargador, Juego *juego);
		void crear(Mapa* mapa);
};

#endif //BUMBY_FACTORY_H
