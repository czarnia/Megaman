#include "strategy_mover_izquierda.h"

#include <iostream>

StrategyMoverIzquierda::StrategyMoverIzquierda(Mapa &mapa):
StrategyMover(mapa){
	nombre_senial = std::string("<-");
}

Coordenada* StrategyMoverIzquierda::nueva_coordenada(Coordenada &coord){
	std::cout << "MUEVO IZQ\n";
	Coordenada coord_izq = coord.izquierda();
	size_t x = coord_izq.obtener_abscisa();
	size_t y = coord_izq.obtener_ordenada();
	return new Coordenada(x, y);
}

StrategyMoverIzquierda::~StrategyMoverIzquierda(){}
