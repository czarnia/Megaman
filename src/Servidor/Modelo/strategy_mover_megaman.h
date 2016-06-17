#ifndef STRATEGY_MOVER_MEGAMAN_H
#define STRATEGY_MOVER_MEGAMAN_H

#include "strategy_mover_personaje_pc.h"
#include "megaman.h"
#include "coordenada.h"

class StrategyMoverMegaman : public StrategyMoverPersonajePc{
	private:
		int velocidad_x;
		int velocidad_y;
	public:
		StrategyMoverMegaman();
		virtual void mover(Mapa *mapa, Personaje_pc *pj, size_t tiempo);
		void agregar_movimiento(Personaje_pc *pj, int dir);
		void sacar_movimiento(Personaje_pc *pj, int dir);
		~StrategyMoverMegaman();
};

#endif //STRATEGY_MOVER_MEGAMAN_H
