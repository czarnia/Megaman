#include "strategy_mover_personaje_pc.h"
#include <iostream>

#define MOVIMIENTO_MAX 6
enum movimientos{QUIETO, ARRIBA, ABAJO, DERECHA, IZQUIERDA, SALTAR};
enum estados_pc{RESPAWNEANDO = 1, CORRIENDO, SALTANDO, IDLE, 
		DISPARANDO, ESCALANDO};	
		
StrategyMoverPersonajePc::StrategyMoverPersonajePc(){
	direccion = QUIETO;
}

void StrategyMoverPersonajePc::mover(Mapa *mapa, Personaje_pc *pj, size_t tiempo){
	if (direccion == QUIETO){
		return;
	}
	Coordenada coord_nueva = pj->coordenada;
	switch(direccion){
		case ARRIBA:
			coord_nueva = pj->coordenada.arriba();
			direccion = ARRIBA;
			pj->estado_actual = ESCALANDO;
			break;
		case ABAJO:
			coord_nueva = pj->coordenada.abajo();
			direccion = ABAJO;
			break;
		case DERECHA:
			coord_nueva = pj->coordenada.derecha();
			direccion = DERECHA;
			pj->estado_actual = CORRIENDO;
			break;
		case IZQUIERDA:
			coord_nueva = pj->coordenada.izquierda();
			direccion = IZQUIERDA;
			pj->estado_actual = CORRIENDO;
			break;
	}
	if (mapa->puede_ubicarse(pj, coord_nueva)){
		pj->coordenada = coord_nueva;
	}
}

void StrategyMoverPersonajePc::sacar_movimiento(Personaje_pc *pj, int dir){
	direccion = QUIETO;	
	pj->estado_actual = IDLE;
}

void StrategyMoverPersonajePc::set_direccion_abajo(){
	direccion = ABAJO;
}

void StrategyMoverPersonajePc::set_direccion_arriba(){
	direccion = ARRIBA;
}

void StrategyMoverPersonajePc::set_direccion_derecha(){
	direccion = DERECHA;
}

void StrategyMoverPersonajePc::set_direccion_izquierda(){
	direccion = IZQUIERDA;
}
