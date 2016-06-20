#include "strategy_mover_snipper.h"
#include "snipper.h"

#define VELOCIDAD 10
#define TIEMPO_DIRECCION 0.1

enum direccion{DERECHA, IZQUIERDA};

StrategyMoverSnipper::StrategyMoverSnipper(){
	direccion = DERECHA;
	tiempo_pasado = 0;
}

void StrategyMoverSnipper::mover(Mapa *mapa, Snipper *pj, float tiempo){
	Coordenada coord_nueva = pj->coordenada;
	tiempo_pasado += tiempo;
	if (tiempo_pasado >= TIEMPO_DIRECCION){
		cambiar_direccion();
		tiempo_pasado -= TIEMPO_DIRECCION;
	}
	switch(direccion){
		case DERECHA:
			coord_nueva = pj->coordenada.derecha(VELOCIDAD);
			break;
		case IZQUIERDA:
			coord_nueva = pj->coordenada.izquierda(VELOCIDAD);
			break;
	}
	if (mapa->puede_ubicarse(pj, coord_nueva)){
		pj->coordenada = coord_nueva;
		pj->notificar_observadores();
	}
}

void StrategyMoverSnipper::cambiar_direccion(){
	if (direccion == DERECHA){
		direccion = IZQUIERDA;
	}else{
		direccion = DERECHA;
	}
}
