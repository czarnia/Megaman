#ifndef STRATEGY_MOVER_MEGNETMAN_H
#define STRATEGY_MOVER_MEGNETMAN_H

#include "personaje_npc.h"
#include "strategy_mover.h"
#include <vector>

class Magnetman;

class StrategyMoverMagnetman : public StrategyMover{
	private:
		int velocidad_x;
		int velocidad_y;
		float tiempo_salto;
		float tiempo_mover;
		
		void perseguir_enemigo(Mapa *mapa, Magnetman *pj);
		void actualizar_coordenada(Mapa *mapa, Magnetman *pj);
	public:
		//Crea un StrategyMoverMagnetman.
		StrategyMoverMagnetman();
		//Dado un Mapa*, un Magnetman* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Magnetman *pj, float tiempo);
		//Destructor del StrategyMoverMagnetman.
		virtual ~StrategyMoverMagnetman();
};

#endif //STRATEGY_MOVER_MEGNETMAN_H

