#ifndef JUMPING_SNIPPER_H
#define JUMPING_SNIPPER_H

#include "snipper.h"
#include "strategy_mover_jumping_snipper.h"

class JumpingSnipper : public Snipper {
	private:
		StrategyMoverJumpingSnipper salto_snipper;
	public:
		JumpingSnipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		//Le hace un update al personaje.
		virtual void update(size_t tiempo, Mapa* mapa);
};

#endif //JUMPING_SNIPPER_H
