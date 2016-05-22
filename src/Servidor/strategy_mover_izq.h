#ifndef STRATEGY_MOVER_IZQ_H
#define STRATEGY_MOVER_IZQ_H

#include "strategy_mover.h"
#include "personaje.h"
#include "mapa.h"
#include <string>

class StrategyMoverIzquierda: public StrategyMover{
	public:
		StrategyMoverIzquierda(Mapa &mapa);
		~StrategyMoverIzquierda();
	private:
		Coordenada *nueva_coordenada(Coordenada &coord);
};

#endif //STRATEGY_MOVER_IZQ_H
