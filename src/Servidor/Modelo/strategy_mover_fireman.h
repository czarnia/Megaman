#ifndef STRATEGY_MOVER_FIREMAN_H
#define STRATEGY_MOVER_FIREMAN_H

#include "personaje_npc.h"
#include "strategy_mover.h"
#include <vector>

class Fireman;

class StrategyMoverFireman : public StrategyMover{
	private:
		int velocidad_x;
		int velocidad_y;
		float tiempo_salto;
		float tiempo_mover;
		
		void perseguir_enemigo(Mapa *mapa, Fireman *pj);
		void actualizar_coordenada(Mapa *mapa, Fireman *pj);
	public:
		//Crea un StrategyMoverFireman.
		StrategyMoverFireman();
		//Dado un Mapa*, un Fireman* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Fireman *pj, float tiempo);
		//Destructor del StrategyMoverFireman.
		virtual ~StrategyMoverFireman();
};

#endif //STRATEGY_MOVER_FIREMAN_H
