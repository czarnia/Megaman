#ifndef STRATEGY_MOVER_IZQ_H
#define STRATEGY_MOVER_IZQ_H

#include "strategy.h"
#include "personaje.h"
#include "mapa.h"
#include <string>

class StrategyMoverIzquierda: StrategyMover{
	public:
		StrategyMoverIzquierda::StrategyMoverIzquierda(Mapa &mapa);
		void mover(Personaje &personaje);
	private:
		Mapa &mapa;
		std::string nombre_senial;
		
		Coordenada *nueva_coordenada(Coordenada &coord);
};

#endif //STRATEGY_MOVER_IZQ_H
