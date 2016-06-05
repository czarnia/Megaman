#ifndef PUAS_FACTORY_H
#define PUAS_FACTORY_H

#include "ubicable_factory.h"
#include "../Servidor/Modelo/juego.h"
#include <map>

class Puas_factory : public Ubicable_factory{
	public:
		//Crea un megaman factory.
		Puas_factory();
		//Dado un mapa y una coordenada, crea a un Puas.
		virtual Ubicable* crear(Mapa* mapa, Coordenada coord);
};

#endif //PUAS_FACTORY_H
