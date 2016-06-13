#ifndef UBICABLE_FACTORY_H
#define UBICABLE_FACTORY_H

#include "mapa.h"
#include "ubicable.h"

class Juego;
class Cargador_mapa;

class Ubicable_factory{
	protected:
		Cargador_mapa *cargador_mapa;
		Juego *juego;
	public:
		Ubicable_factory(Cargador_mapa * cargador, Juego *juego):
		cargador_mapa(cargador), juego(juego){}
		//Dado un mapa, crea a un ubicable.
		virtual Ubicable* crear(Mapa* mapa) = 0;
		//Destructor del ubicable.
		virtual ~Ubicable_factory() {}
};

#endif //UBICABLE_FACTORY_H
