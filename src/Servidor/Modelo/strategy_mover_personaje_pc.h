#ifndef STRATEGY_MOVER_PERSONAJE_PC_H
#define STRATEGY_MOVER_PERSONAJE_PC_H

#include "strategy_mover.h"
#include "personaje_pc.h"

class Personaje_pc;

class StrategyMoverPersonajePc : public StrategyMover{
	public:
		StrategyMoverPersonajePc();
		virtual void mover(Mapa *mapa, Personaje_pc *pj, size_t tiempo);
		virtual void set_direccion_abajo();
		virtual void set_direccion_arriba();
		virtual void set_direccion_derecha();
		virtual void set_direccion_izquierda();
		virtual void sacar_movimiento(Personaje_pc *pj, int dir);
};

#endif //STRATEGY_MOVER_PERSONAJE_PC_H
