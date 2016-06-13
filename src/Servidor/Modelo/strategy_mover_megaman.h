#ifndef STRATEGY_MOVER_MEGAMAN_H
#define STRATEGY_MOVER_MEGAMAN_H

#include "strategy_mover.h"
#include "coordenada.h"

class StrategyMoverMegaman : public StrategyMover{
	private:
		int velocidad_x;
		int velocidad_y;
	public:
		StrategyMoverMegaman();
		void mover(Mapa *mapa, Personaje *pj, size_t tiempo);
		void agregar_movimiento(Personaje *pj, int dir);
		void sacar_movimiento(Personaje *pj, int dir);
		~StrategyMoverMegaman();
};

#endif //STRATEGY_MOVER_MEGAMAN_H
