#include "escalera.h"
#include "strategy_mover_arriba.h"

bool Escalera::puede_ocupar(Personaje* pj){
	return true;
}

void Escalera::interactuar(Mapa &mapa, Personaje *pj){
	StrategyMoverArriba *subir = new StrategyMoverArriba(mapa);
	pj->agregar_estrategia(*subir);
}

Escalera::~Escalera() {}
