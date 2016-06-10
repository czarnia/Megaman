#ifndef STRATEGY_SUBIR_H
#define STRATEGY_SUBIR_H

#include "strategy_mover.h"

class StrategySubir : public StrategyMover{
	public:
		void mover(Mapa *mapa, Personaje *pj);
		int get_direccion();
};

#endif //STRATEGY_SUBIR_H
