#ifndef MET_FACTORY_H
#define MET_FACTORY_H

#include "ubicable_factory.h"
#include "factory_observador_ubicable.h"
#include "juego.h"
#include "../../Editor/cargador_mapa.h"
#include <map>

class Met_factory : public Ubicable_factory{
	private:
		Factory_observador_ubicable fact_obs;
	public:
		//Dado un puntero a un juego, crea un megaman factory.
		Met_factory(Cargador_mapa * cargador, Juego *juego);
		//Dado un mapa, crea y ubica los mets.
		void crear(Mapa* mapa);
};

#endif //MET_FACTORY_H
