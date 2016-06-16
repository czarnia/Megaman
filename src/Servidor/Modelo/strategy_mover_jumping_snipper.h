#ifndef STRATEGY_MOVER_JUMPING_SNIPPER_H
#define STRATEGY_MOVER_JUMPING_SNIPPER_H

#include "strategy_mover.h"
#include "personaje.h"

class StrategyMoverJumpingSnipper : public StrategyMover{
	protected:
		int direccion;
		size_t tiempo_pasado;
		bool flotando;
	public:
		virtual void mover(Mapa *mapa, Personaje *pj, size_t tiempo);
};

#endif //STRATEGY_MOVER_JUMPING_SNIPPER_H
