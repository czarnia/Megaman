#ifndef STRATEGY_MOVER_H
#define STRATEGY_MOVER_H

#include "mapa.h"
#include "personaje.h"

class Personaje;
class Mapa;

class StrategyMover{
	protected:
		int direccion;
	public:
		virtual void mover(Mapa *mapa, Personaje *pj, size_t tiempo) = 0;
		int get_direccion(){ return direccion; }
};

#endif //STRATEGY_MOVER_H

