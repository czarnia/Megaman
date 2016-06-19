#ifndef STRATEGY_MOVER_PERSONAJE_PC_H
#define STRATEGY_MOVER_PERSONAJE_PC_H

#include "strategy_mover.h"
#include "personaje_pc.h"

class Personaje_pc;

class StrategyMoverPersonajePc : public StrategyMover{
	public:
		//Crea un StrategyMoverPersonajePc.
		StrategyMoverPersonajePc();
		//Dado un Mapa*, un Personaje_pc* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Personaje_pc *pj, float tiempo);
		//Setea la direccion abajo.
		virtual void set_direccion_abajo();
		//Setea la direccion arriba.
		virtual void set_direccion_arriba();
		//Setea la direccion derecha.
		virtual void set_direccion_derecha();
		//Setea la direccion izquierda.
		virtual void set_direccion_izquierda();
		//Dado un Personaje_pc*, le saca un movimiento.
		virtual void sacar_movimiento(Personaje_pc *pj, int dir);
};

#endif //STRATEGY_MOVER_PERSONAJE_PC_H
