#ifndef STRATEGY_MOVER_BUMBY
#define STRATEGY_MOVER_BUMBY

#include "strategy_mover.h"

class Bumby;

class StrategyMoverBumby : public StrategyMover{
	protected:
		int direccion;
	public:
		//Crea un StrategyMoverBumby.
		StrategyMoverBumby();
		//Dado un Mapa*, un Bumby* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Bumby *pj, size_t tiempo);
		//Destructor del StrategyMoverBumby.
		//virtual ~StrategyMoverBumby();
};

#endif //STRATEGY_MOVER_BUMBY
