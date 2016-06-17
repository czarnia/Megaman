#ifndef STRATEGY_MOVER_BUMBY
#define STRATEGY_MOVER_BUMBY

#include "strategy_mover.h"

class Bumby;

class StrategyMoverBumby : public StrategyMover{
	protected:
		int direccion;
	public:
		StrategyMoverBumby();
		virtual void mover(Mapa *mapa, Bumby *pj, size_t tiempo);	
};

#endif //STRATEGY_MOVER_BUMBY
