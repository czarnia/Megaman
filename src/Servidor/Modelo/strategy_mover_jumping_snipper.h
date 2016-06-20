#ifndef STRATEGY_MOVER_JUMPING_SNIPPER_H
#define STRATEGY_MOVER_JUMPING_SNIPPER_H

#include "strategy_mover.h"

class Jumping_snipper;

class StrategyMoverJumpingSnipper : public StrategyMover{
	protected:
		int direccion;
		float tiempo_pasado;
		bool flotando;
		int velocidad_y;
	public:
		StrategyMoverJumpingSnipper();
		//Dado un Mapa*, un JumpingSnipper* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Jumping_snipper *pj, float tiempo);
		//Destructor del StrategyMoverJumpingSnipper.
		virtual ~StrategyMoverJumpingSnipper() {}
};

#endif //STRATEGY_MOVER_JUMPING_SNIPPER_H
