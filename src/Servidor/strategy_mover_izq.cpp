#include "strategy_mover_izq.h"

StrategyMoverIzquierda::StrategyMoverIzquierda(Mapa &mapa): 
StrategyMover(mapa){
	nombre_senial = std::string("<-");
}

Coordenada* StrategyMoverIzquierda::nueva_coordenada(Coordenada &coord){
	Coordenada coord_izq = coord.izquierda();
	size_t x = coord_izq.obtener_abcisa();
	size_t y = coord_izq.obtener_ordenada();
	return new Coordenada(x, y);
}

