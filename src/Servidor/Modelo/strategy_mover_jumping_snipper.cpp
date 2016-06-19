#include "strategy_mover_jumping_snipper.h"
#include "jumping_snipper.h"

#define TIEMPO_SALTO 4

void StrategyMoverJumpingSnipper::mover(Mapa *mapa, Jumping_snipper *pj, float tiempo){
	tiempo_pasado += tiempo;
	Coordenada nueva_coord(-1, -1);
	if (tiempo_pasado >= TIEMPO_SALTO){
		tiempo_pasado = 0;
		return;
	}
	if (tiempo_pasado >= (TIEMPO_SALTO/2)){
		nueva_coord = nueva_coord.abajo();
	}else{
		nueva_coord = nueva_coord.arriba();
	}
	if (mapa->puede_ubicarse(pj, nueva_coord)){
		pj->coordenada = nueva_coord;
		pj->notificar_observadores();
	}
}
