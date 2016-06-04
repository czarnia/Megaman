#ifndef PERSONAJE_FACTORY_H
#define PERSONAJE_FACTORY_H

#include "personaje.h"
#include "observador.h"
#include "observable.h"

class Juego;

class PersonajeFactory:
public Observador{
	protected:
		Juego *juego;
	public:
		//Dado un puntero a un juego, crea un personaje factory.
		PersonajeFactory(Juego *juego):juego(juego){};
		//Dado un mapa, crea a un personaje.
		virtual Personaje *crear(Mapa* mapa) = 0;
		virtual void update(Observable *obs) = 0;
};

#endif //PERSONAJE_FACTORY_H
