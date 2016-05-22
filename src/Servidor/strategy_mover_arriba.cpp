#include "strategy_mover_arriba.h"

StrategyMoverArriba::StrategyMoverArriba(Mapa &mapa): 
StrategyMover(mapa){
	nombre_senial = std::string("<-");
}

Coordenada* StrategyMoverArriba::nueva_coordenada(Coordenada &coord){
	Coordenada coord_izq = coord.arriba();
	size_t x = coord_izq.obtener_abscisa();
	size_t y = coord_izq.obtener_ordenada();
	return new Coordenada(x, y);
}

StrategyMoverArriba::~StrategyMoverArriba(){}

