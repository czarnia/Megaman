#ifndef STRATEGY_MOVER_SIN_GRAVEDAD_H
#define STRATEGY_MOVER_SIN_GRAVEDAD_H

#include "strategy_mover.h"
#include "personaje.h"

class StrategyMoverSinGravedad : public StrategyMover{
	public:
		StrategyMoverSinGravedad();
		void mover(Mapa *mapa, Personaje *pj, size_t tiempo);
		void set_direccion_abajo();
		void set_direccion_arriba();
		void set_direccion_derecha();
		void set_direccion_izquierda();
};

#endif //STRATEGY_MOVER_SIN_GRAVEDAD_H

