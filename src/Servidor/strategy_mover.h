#ifndef STRATEGY_MOVER_H
#define STRATEGY_MOVER_H

#include "personaje.h"
#include "mapa.h"

class StrategyMover{
	public:
		StrategyMover::StrategyMover(Mapa &mapa);
		virutal void mover(Personaje &personaje) = 0;
	private:
		Mapa &mapa;
		int &direccion;
		std::string &nombre_senial;
};

#endif //STRATEGY_MOVER_H
