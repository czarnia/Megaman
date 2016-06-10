#include "strategy_mover_sin_gravedad.h"

void StrategyMoverSinGravedad::mover(Mapa *mapa, Personaje *pj){
	pj->flotando = false;
	if (estrategia){
		estrategia->mover(mapa, pj);
	}
}

