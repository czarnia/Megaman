#include "strategy_mover_izquierda.h"

StrategyMoverIzquierda::StrategyMoverIzquierda(Mapa &mapa):
StrategyMover(mapa){
	nombre_senial = std::string("IZQUIERDA");
}

Coordenada* StrategyMoverIzquierda::nueva_coordenada(Coordenada &coord){
	Coordenada coord_izq = coord.izquierda();
	size_t x = coord_izq.obtener_abscisa();
	size_t y = coord_izq.obtener_ordenada();
	return new Coordenada(x, y);
}

StrategyMoverIzquierda::~StrategyMoverIzquierda(){}
