#ifndef JUMPING_SNIPPER_H
#define JUMPING_SNIPPER_H

#include "snipper.h"
#include "strategy_mover_jumping_snipper.h"

class StrategyMoverJumpingSnipper;

class Jumping_snipper : public Snipper {
	private:
		StrategyMoverJumpingSnipper salto_snipper;
	public:
		//Dado un Mapa*, una coordenada, un Arma_minion* y un id, crea un Jumping_
		//snippper.
		Jumping_snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		//Le hace un update al personaje.
		virtual void update(float tiempo, Mapa* mapa);

		friend class StrategyMoverJumpingSnipper;
};

#endif //JUMPING_SNIPPER_H
