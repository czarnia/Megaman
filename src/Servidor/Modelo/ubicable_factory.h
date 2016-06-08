#ifndef UBICABLE_FACTORY_H
#define UBICABLE_FACTORY_H

#include "mapa.h"
#include "ubicable.h"

class Ubicable_factory{
	public:
		//Dado un mapa y una coordenada, crea a un ubicable.
		virtual Ubicable* crear(Mapa* mapa, Coordenada coord) = 0;
		//Destructor del ubicable.
    virtual ~Ubicable_factory() {}
};

#endif //UBICABLE_FACTORY_H
