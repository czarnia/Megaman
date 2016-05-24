#ifndef STRATEGY_MOVER_CON_GRAVEDAD_H
#define STRATEGY_MOVER_CON_GRAVEDAD_H

#include "strategy_mover.h"
#include "strategy_mover_abajo.h"

class StrategyMoverConGravedad: public StrategyMover{
	public:
		StrategyMoverConGravedad(Mapa &mapa, StrategyMover *movimiento);
		bool ejecutar(Personaje *personaje);
		std::string get_nombre();
		Coordenada *nueva_coordenada(Coordenada &coord);
		~StrategyMoverConGravedad();
	private:
		StrategyMover *movimiento;
		StrategyMoverAbajo *caer;		
};

#endif //STRATEGY_MOVER_CON_GRAVEDAD_H
