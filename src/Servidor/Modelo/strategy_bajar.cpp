#include "strategy_bajar.h"
#include "coordenada.h"
#include "mapa.h"
void StrategyBajar::mover(Mapa *mapa, Personaje *pj){
	Coordenada nueva_pos = pj->coordenada.abajo();
	if (mapa->puede_ubicarse(pj, nueva_pos)){
		pj->coordenada = nueva_pos;
	}
}
