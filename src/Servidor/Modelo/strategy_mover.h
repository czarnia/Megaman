#ifndef STRATEGY_MOVER_H
#define STRATEGY_MOVER_H

#include "mapa.h"

class StrategyMover{
	protected:
		int direccion;
	public:
		int get_direccion(){ return direccion; }
};

#endif //STRATEGY_MOVER_H
