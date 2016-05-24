#include "strategy_mover_abajo.h"

#include <iostream>

StrategyMoverAbajo::StrategyMoverAbajo(Mapa &mapa):
StrategyMover(mapa){
	nombre_senial = std::string("_");
}

Coordenada* StrategyMoverAbajo::nueva_coordenada(Coordenada &coord){
	Coordenada coord_abajo = coord.abajo();
	size_t x = coord_abajo.obtener_abscisa();
	size_t y = coord_abajo.obtener_ordenada();
	return new Coordenada(x, y);
}

StrategyMoverAbajo::~StrategyMoverAbajo(){}
