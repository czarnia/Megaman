#include "strategy_mover_jumping_snipper.h"
#include "jumping_snipper.h"

#define TIEMPO_SALTO 4
#define VELOCIDAD_SALTO 40
#define VELOCIDAD_Y 10
#define GRAVEDAD 5

StrategyMoverJumpingSnipper::StrategyMoverJumpingSnipper(){
	tiempo_pasado = 0;
	velocidad_y = 0;
}

void StrategyMoverJumpingSnipper::mover(Mapa *mapa, Jumping_snipper *pj, float tiempo){
	tiempo_pasado += tiempo;
	Coordenada nueva_coordenada = pj->coordenada;
	if (mapa->esta_en_aire(pj)){
		pj->flotando = true;
		velocidad_y += GRAVEDAD; //valor gravedad.
	}else{
		pj->flotando = false;
	}if ((tiempo_pasado >= (TIEMPO_SALTO)) && (!pj->flotando)){
			velocidad_y -= VELOCIDAD_SALTO;
			tiempo_pasado -= TIEMPO_SALTO;
	}if (velocidad_y < 0){
		nueva_coordenada = nueva_coordenada.arriba(VELOCIDAD_Y);
	}
	if (velocidad_y > 0){
		nueva_coordenada = nueva_coordenada.abajo(VELOCIDAD_Y);
		//pj->estado_actual = SALTANDO;
	}
	if (mapa->puede_ubicarse(pj, nueva_coordenada)){
		pj->coordenada = nueva_coordenada;
		pj->notificar_observadores();
	}
}
