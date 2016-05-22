#ifndef STRATEGY_MOVER_ABAJO_H
#define STRATEGY_MOVER_ABAJO_H

#include "strategy_mover.h"
#include "personaje.h"
#include "mapa.h"
#include <string>

class StrategyMoverAbajo: public StrategyMover{
	public:
		StrategyMoverAbajo(Mapa &mapa);
		~StrategyMoverAbajo();
	private:
		Coordenada *nueva_coordenada(Coordenada &coord);
};

#endif //STRATEGY_MOVER_ABAJO_H
