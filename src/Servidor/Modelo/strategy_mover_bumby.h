#ifndef STRATEGY_MOVER_BUMBY
#define STRATEGY_MOVER_BUMBY

#include "strategy_mover.h"

class Bumby;

class StrategyMoverBumby : public StrategyMover{
	protected:
		int direccion;
		float tiempo_pasado;
	public:
		//Crea un StrategyMoverBumby.
		StrategyMoverBumby();
		//Dado un Mapa*, un Bumby* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Bumby *pj, float tiempo);
		//Destructor del StrategyMoverBumby.
		//virtual ~StrategyMoverBumby();
	private:
		void cambiar_direccion();
};

#endif //STRATEGY_MOVER_BUMBY
