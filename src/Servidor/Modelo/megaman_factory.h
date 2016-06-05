#ifndef MEGAMAN_FACTORY_H
#define MEGAMAN_FACTORY_H

#include "ubicable_factory.h"
#include "juego.h"
#include <map>

class Juego;
class Ubicable_factory;
class Megaman;
class Personaje;

class MegamanFactory : public Ubicable_factory{
	private:
		Juego *juego;
		int creados;
		//std::multimap<Megaman*, Observador*> creados;
	public:
		//Dado un puntero a un juego, crea un megaman factory.
		MegamanFactory(Juego *juego);
		//Dado un mapa, crea a un personaje.
		virtual Ubicable *crear(Mapa* mapa, Coordenada c);
		//Recibe un observable y actualiza su estado.
		//void update(Observable *obs);
};

#endif //MEGAMAN_FACTORY_H
