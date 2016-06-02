#ifndef MEGAMAN_FACTORY_H
#define MEGAMAN_FACTORY_H

#include "personaje_factory.h"
#include "observador_personaje.h"
#include <map>

class Juego;

class MegamanFactory:
public PersonajeFactory{
	private:
		std::map<Megaman*, ObservadorPersonaje*> creados;
	public:
		//Dado un puntero a un juego, crea un megaman factory.
		MegamanFactory(Juego *juego);
		//Dado un mapa, crea a un personaje.
		virtual Personaje *crear(Mapa* mapa);
		//?
		virtual void update(Observable *obs);
};

#endif //MEGAMAN_FACTORY_H
