#include "strategy_mover_sin_gravedad.h"

enum movimientos{QUIETO, ARRIBA, ABAJO, DERECHA, IZQUIERDA, SALTAR};

StrategyMoverSinGravedad::StrategyMoverSinGravedad(){
	direccion = QUIETO;
}

void StrategyMoverSinGravedad::mover(Mapa *mapa, Personaje *pj){
	Coordenada coord_nueva = pj->coordenada;
	switch(direccion){
		case QUIETO:
			direccion = QUIETO;
			break;
		case ARRIBA:
			coord_nueva = pj->coordenada.arriba();
			direccion = ARRIBA;
			break;
		case ABAJO:
			coord_nueva = pj->coordenada.abajo();
			direccion = ABAJO;
			break;
		case DERECHA:
			coord_nueva = pj->coordenada.derecha();
			direccion = DERECHA;
			break;
		case IZQUIERDA:
			coord_nueva = pj->coordenada.izquierda();
			direccion = IZQUIERDA;
			break;
	}
	if (mapa->puede_ubicarse(pj, coord_nueva)){
		pj->coordenada = coord_nueva;
	}
}
void StrategyMoverSinGravedad::set_direccion_abajo(){
	direccion = ABAJO;
}

void StrategyMoverSinGravedad::set_direccion_arriba(){
	direccion = ARRIBA;
}

void StrategyMoverSinGravedad::set_direccion_derecha(){
	direccion = DERECHA;
}

void StrategyMoverSinGravedad::set_direccion_izquierda(){
	direccion = IZQUIERDA;
}

