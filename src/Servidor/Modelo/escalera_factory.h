#ifndef ESCALERA_FACTORY_H
#define ESCALERA_FACTORY_H

#include "ubicable_factory.h"
#include "../Servidor/Modelo/juego.h"
#include <map>

class Escalera_factory : public Ubicable_factory{
	public:
		//Crea un megaman factory.
		Escalera_factory();
		//Dado un mapa y una coordenada, crea a un Escalera.
		virtual Ubicable* crear(Mapa* mapa, Coordenada coord);
};

#endif //ESCALERA_FACTORY_H
