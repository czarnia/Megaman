#ifndef BLOQUE_FACTORY_H
#define BLOQUE_FACTORY_H

#include "ubicable_factory.h"
#include "../Servidor/Modelo/juego.h"
#include <map>

class Bloque_factory : public Ubicable_factory{
	public:
		//Crea un megaman factory.
		Bloque_factory();
		//Dado un mapa y una coordenada, crea a un Bloque.
		virtual Ubicable* crear(Mapa* mapa, Coordenada coord);
};

#endif //BLOQUE_FACTORY_H