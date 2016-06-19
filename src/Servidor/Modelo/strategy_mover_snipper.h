#ifndef STRATEGY_MOVER_SNIPPER_H
#define STRATEGY_MOVER_SNIPPER_H

#include "strategy_mover.h"

class Snipper;

class StrategyMoverSnipper : public StrategyMover{
	protected:
		int direccion;
		float tiempo_pasado;
	public:
		//Constructor del StrategyMoverSnipper.
		StrategyMoverSnipper();
		//Dado un Mapa*, un JumpingSnipper* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Snipper *pj, float tiempo);
		//Destructor del StrategyMoverJumpingSnipper.
		virtual ~StrategyMoverSnipper() {}
	private:
		//Cambia la direccion de movimiento.
		void cambiar_direccion();
};

#endif //STRATEGY_MOVER_SNIPPER_H
