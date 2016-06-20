#ifndef STRATEGY_MOVER_BOMBMAN_H
#define STRATEGY_MOVER_BOMBMAN_H

#include "personaje_npc.h"
#include "strategy_mover.h"
#include <vector>

class Bombman;

class StrategyMoverBombman : public StrategyMover{
	private:
		int velocidad_x;
		int velocidad_y;
		float tiempo_salto;

		void actualizar_coordenada(Mapa *mapa, Bombman *pj,
		Coordenada *coord);
	public:
		//Crea un StrategyMoverBombman.
		StrategyMoverBombman();
		//Dado un Mapa*, un Bombman* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Bombman *pj, float tiempo);
		//Destructor del StrategyMoverBombman.
		virtual ~StrategyMoverBombman();
};

#endif //STRATEGY_MOVER_BOMBMAN_H

