#include "escalera.h"
#include "strategy_mover_arriba.h"
#include "strategy_mover_abajo.h"

bool Escalera::puede_ocupar(Personaje* pj){
	return true;
}

void Escalera::interactuar(Mapa &mapa, Personaje *pj){
	StrategyMoverArriba *subir = new StrategyMoverArriba(mapa);
	StrategyMoverAbajo *bajar = new StrategyMoverAbajo(mapa);
	pj->agregar_estrategia(*subir);
	pj->agregar_estrategia(*bajar);
}

Escalera::~Escalera() {}
