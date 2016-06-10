#ifndef STRATEGY_MOVER_SIN_GRAVEDAD_H
#define STRATEGY_MOVER_SIN_GRAVEDAD_H

#include "strategy_mover.h"
#include "personaje.h"

class StrategyMoverSinGravedad : public StrategyMover{
	private:
		StrategyMover* estrategia;
	public:
		void mover(Mapa *mapa, Personaje *pj);
		int get_direccion();
};

#endif //STRATEGY_MOVER_SIN_GRAVEDAD_H

