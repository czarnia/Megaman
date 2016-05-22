#ifndef STRATEGY_MOVER_H
#define STRATEGY_MOVER_H

#include "personaje.h"
#include "mapa.h"
#include <string>

class StrategyMover{
	public:
		StrategyMover::StrategyMover(Mapa &mapa);
		virutal void mover(Personaje *personaje) = 0;
		virtual ~StrategyMover() = 0;
	private:
		Mapa &mapa;
		std::string nombre_senial;
		
		virtual Coordenada *nueva_coordenada(Coordenada &coord) = 0;
};

#endif //STRATEGY_MOVER_H
