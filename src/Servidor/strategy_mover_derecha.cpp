#include "strategy_mover_derecha.h"

StrategyMoverDerecha::StrategyMoverDerecha(Mapa &mapa):
StrategyMover(mapa){
	nombre_senial = std::string("->");
}

Coordenada* StrategyMoverDerecha::nueva_coordenada(Coordenada &coord){
	Coordenada coord_derecha = coord.derecha();
	size_t x = coord_derecha.obtener_abscisa();
	size_t y = coord_derecha.obtener_ordenada();
	return new Coordenada(x, y);
}

StrategyMoverDerecha::~StrategyMoverDerecha(){}
