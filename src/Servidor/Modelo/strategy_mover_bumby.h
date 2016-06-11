#ifndef STRATEGY_MOVER_BUMBY
#define STRATEGY_MOVER_BUMBY

#include "strategy_mover.h"
#include "personaje.h"

class StrategyMoverBumby : public StrategyMover{
	protected:
		int direccion;
	public:
		StrategyMoverBumby();
		virtual void mover(Mapa *mapa, Personaje *pj, size_t tiempo);	
};

#endif //STRATEGY_MOVER_BUMBY
