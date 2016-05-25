#ifndef STRATEGY_MOVER_DERECHA_H
#define STRATEGY_MOVER_DERECHA_H

#include "strategy_mover.h"
#include "personaje.h"
#include "mapa.h"
#include <string>

class StrategyMoverDerecha: public StrategyMover{
	public:
		StrategyMoverDerecha(Mapa &mapa);
		~StrategyMoverDerecha();
	private:
		Coordenada *nueva_coordenada(Coordenada &coord);
};

#endif //STRATEGY_MOVER_DERECHA_H
