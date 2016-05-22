#ifndef STRATEGY_MOVER_ARRIBA_H
#define STRATEGY_MOVER_ARRIBA_H

#include "strategy_mover.h"
#include "personaje.h"
#include "mapa.h"
#include <string>

class StrategyMoverArriba: public StrategyMover{
	public:
		StrategyMoverArriba(Mapa &mapa);
		void mover(Personaje &personaje);
		~StrategyMoverArriba();
	private:
		Coordenada *nueva_coordenada(Coordenada &coord);
};

#endif //STRATEGY_MOVER_ARRIBA_H

