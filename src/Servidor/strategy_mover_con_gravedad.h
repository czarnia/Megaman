#ifndef STRATEGY_MOVER_CON_GRAVEDAD_H
#define STRATEGY_MOVER_CON_GRAVEDAD_H

#include "strategy_mover.h"
#include "strategy_mover_abajo.h"

class StrategyMoverConGravedad{
	public:
		StrategyMoverConGravedad(Mapa &mapa, StrategyMover *movimiento);
		bool ejecutar(Personaje *personaje);
		~StrategyMoverConGravedad();
	private:
		Mapa &mapa;
		StrategyMover *movimiento;
		StrategyMoverAbajo *caer;		
		
		Coordenada *nueva_coordenada(Coordenada &coord);
};

#endif //STRATEGY_MOVER_CON_GRAVEDAD_H
