#ifndef BOSS_FACTORY_H
#define BOSS_FACTORY_H

#include "ubicable_factory.h"
#include "factory_observador_ubicable.h"
#include "../../Editor/cargador_mapa.h"
#include "juego.h"
#include <map>

class Juego;
class Ubicable_factory;
class Personaje;

class Boss_factory : public Ubicable_factory{
	private:
		Factory_observador_ubicable fact_obs;
	public:
		//Dados un puntero a un juego y un puntero a un cargador de 
		//mapas, crea un un boss factory.
		Boss_factory(Cargador_mapa * cargador, Juego *juego);
		//Dado un mapa, crea a un personaje.
		void crear(Mapa* mapa);
};

#endif //BOSS_FACTORY_H
