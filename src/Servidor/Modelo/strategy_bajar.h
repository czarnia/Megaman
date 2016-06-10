#ifndef STRATEGY_BAJAR_H
#define STRATEGY_BAJAR_H

#include "strategy_mover.h"

class StrategyBajar : public StrategyMover{
	public:
		void mover(Mapa *mapa, Personaje *pj);
		int get_direccion();
};

#endif //STRATEGY_BAJAR_H
