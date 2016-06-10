#include "strategy_subir.h"
#include "coordenada.h"
#include "mapa.h"

void StrategySubir::mover(Mapa *mapa, Personaje *pj){
	Coordenada nueva_pos = pj->coordenada.arriba();
	if (mapa->puede_ubicarse(pj, nueva_pos)){
		pj->coordenada = nueva_pos;
	}
}


