#ifndef STRATEGY_MOVER_SPARKMAN_H
#define STRATEGY_MOVER_SPARKMAN_H

#include "personaje_npc.h"
#include "strategy_mover.h"
#include <vector>

class Sparkman;

class StrategyMoverSparkman : public StrategyMover{
	private:
		int velocidad_x;
		int velocidad_y;
		size_t tiempo_salto;

		void saltar(Mapa *mapa, Sparkman *pj);
		void actualizar_coordenada(Mapa *mapa, Sparkman *pj,
		Coordenada *coord);
	public:
		StrategyMoverSparkman();
		virtual void mover(Mapa *mapa, Sparkman *pj, size_t tiempo);
		virtual ~StrategyMoverSparkman();
};

#endif //STRATEGY_MOVER_SPARKMAN_H
