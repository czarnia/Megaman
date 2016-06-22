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
		float tiempo_salto;

		void actualizar_coordenada(Mapa *mapa, Sparkman *pj);
	public:
		//Crea un StrategyMoverSparkman.
		StrategyMoverSparkman();
		//Dado un Mapa*, un Sparkman* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Sparkman *pj, float tiempo);
		//Destructor del StrategyMoverSparkman.
		virtual ~StrategyMoverSparkman();
};

#endif //STRATEGY_MOVER_SPARKMAN_H
