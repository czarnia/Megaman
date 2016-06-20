#include "strategy_mover_bumby.h"
#include "bumby.h"

#define VELOCIDAD 5
#define TIEMPO_DIRECCION 0.1

enum movimientos{ARRIBA_DERECHA, ARRIBA_IZQUIERDA, ABAJO_DERECHA, ABAJO_IZQUIERDA};

StrategyMoverBumby::StrategyMoverBumby(){
	direccion = ABAJO_DERECHA;
}

void StrategyMoverBumby::mover(Mapa *mapa, Bumby *pj, float tiempo){
	Coordenada coord_nueva = pj->coordenada;
	tiempo_pasado += tiempo;
	if (tiempo_pasado > TIEMPO_DIRECCION){
		cambiar_direccion();
		tiempo_pasado -= TIEMPO_DIRECCION;
	}
	switch(direccion){
		case ABAJO_DERECHA:
			coord_nueva = pj->coordenada.derecha(VELOCIDAD).abajo(VELOCIDAD);
			break;
		case ABAJO_IZQUIERDA:
			coord_nueva = pj->coordenada.izquierda(VELOCIDAD).abajo(VELOCIDAD);
			break;
		case ARRIBA_IZQUIERDA:
			coord_nueva = pj->coordenada.izquierda(VELOCIDAD).arriba(VELOCIDAD);
			break;
		case ARRIBA_DERECHA:
			coord_nueva = pj->coordenada.derecha(VELOCIDAD).arriba(VELOCIDAD);
			break;
	}
	if (mapa->puede_ubicarse(pj, coord_nueva)){
		pj->coordenada = coord_nueva;
		pj->notificar_observadores();
	}
}

void StrategyMoverBumby::cambiar_direccion(){
	switch(direccion){
		case ABAJO_DERECHA:
			direccion = ABAJO_IZQUIERDA;
			break;
		case ABAJO_IZQUIERDA:
			direccion = ARRIBA_IZQUIERDA;
			break;
		case ARRIBA_IZQUIERDA:
			direccion = ARRIBA_DERECHA;
			break;
		case ARRIBA_DERECHA:
			direccion = ABAJO_DERECHA;
			break;
	}
}
