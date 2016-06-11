#include "strategy_mover_bumby.h"

enum movimientos{QUIETO = 0, DERECHA = 3, IZQUIERDA = 4};

StrategyMoverBumby::StrategyMoverBumby(){
	direccion = QUIETO;
}

void StrategyMoverBumby::mover(Mapa *mapa, Personaje *pj){
	Coordenada coord_nueva = pj->coordenada;
	switch(direccion){
		case QUIETO:
			break;
		case DERECHA:
			coord_nueva = pj->coordenada.derecha();
			break;
		case IZQUIERDA:
			coord_nueva = pj->coordenada.izquierda();
			break;
	}
	if (mapa->puede_ubicarse(pj, coord_nueva)){
		pj->coordenada = coord_nueva;
	}
}

