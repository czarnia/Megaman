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
		size_t tiempo_salto;
		
		void saltar(Mapa *mapa, Fireman *pj);
		void actualizar_coordenada(Mapa *mapa, Fireman *pj, 
		Coordenada *coord);
	public:
		StrategyMoverFireman();
		virtual void mover(Mapa *mapa, Fireman *pj, size_t tiempo);
		virtual ~StrategyMoverFireman();
};

#endif //STRATEGY_MOVER_FIREMAN_H
