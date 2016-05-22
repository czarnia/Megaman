#ifndef STRATEGY_MOVER_H
#define STRATEGY_MOVER_H

#include "mapa.h"
#include <string>

class Personaje;

class StrategyMover{
	public:
		StrategyMover(Mapa &mapa);
		virtual std::string get_nombre();
		virtual void mover(Personaje *personaje);
		virtual ~StrategyMover() = 0;
	protected:
		Mapa &mapa;
		std::string nombre_senial;

		virtual Coordenada *nueva_coordenada(Coordenada &coord) = 0;
};

#endif //STRATEGY_MOVER_H
