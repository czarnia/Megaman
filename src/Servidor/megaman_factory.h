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
		MegamanFactory(Juego *juego);
		virtual Personaje *crear(Mapa* mapa);
		virtual void update(Observable *obs);
};

#endif //MEGAMAN_FACTORY_H
