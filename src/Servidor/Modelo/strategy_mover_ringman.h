#ifndef STRATEGY_MOVER_RINGMAN_H
#define STRATEGY_MOVER_RINGMAN_H

#include "personaje_npc.h"
#include "strategy_mover.h"
#include <vector>

class Ringman;

class StrategyMoverRingman : public StrategyMover{
	private:
		int velocidad_x;
		int velocidad_y;
		float tiempo_salto;

		void actualizar_coordenada(Mapa *mapa, Ringman *pj);
	public:
		//Crea un StrategyMoverRingman.
		StrategyMoverRingman();
		//Dado un Mapa*, un Ringman* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Ringman *pj, float tiempo);
		//Destructor del StrategyMoverRingman.
		virtual ~StrategyMoverRingman();
};

#endif //STRATEGY_MOVER_RINGMAN_H
