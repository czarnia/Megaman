#ifndef UBICABLE_FACTORY_H
#define UBICABLE_FACTORY_H

#include "mapa.h"
#include "ubicable.h"

class Ubicable_factory{
	public:
		//Dado un mapa, crea a un personaje.
		virtual Ubicable* crear(Mapa* mapa, Coordenada coord) = 0;
    virtual ~Ubicable_factory() {}
};

#endif //UBICABLE_FACTORY_H
