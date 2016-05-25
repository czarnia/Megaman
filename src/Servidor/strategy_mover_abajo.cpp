#include "strategy_mover_abajo.h"

StrategyMoverAbajo::StrategyMoverAbajo(Mapa &mapa):
StrategyMover(mapa){
	nombre_senial = std::string("ABAJO");
}

Coordenada* StrategyMoverAbajo::nueva_coordenada(Coordenada &coord){
	Coordenada coord_abajo = coord.abajo();
	size_t x = coord_abajo.obtener_abscisa();
	size_t y = coord_abajo.obtener_ordenada();
	return new Coordenada(x, y);
}

StrategyMoverAbajo::~StrategyMoverAbajo(){}
