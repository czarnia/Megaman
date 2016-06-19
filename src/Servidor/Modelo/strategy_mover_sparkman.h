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

		void aplicar_movimiento(Mapa *mapa, Sparkman *pj);
		void actualizar_coordenada(Mapa *mapa, Sparkman *pj,
		Coordenada *coord);
	public:
		//Crea un StrategyMoverSparkman.
		StrategyMoverSparkman();
		//Dado un Mapa*, un Sparkman* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Sparkman *pj, size_t tiempo);
		//Destructor del StrategyMoverSparkman.
		virtual ~StrategyMoverSparkman();
};

#endif //STRATEGY_MOVER_SPARKMAN_H
