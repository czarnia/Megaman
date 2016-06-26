#include "strategy_mover_ringman.h"
#include "ringman.h"
#include <stdlib.h>

#define TIEMPO_SALTO 2000
#define GRAVEDAD 5
#define VELOCIDAD_Y 60
#define VELOCIDAD_X 6
#define VELOCIDAD_SALTO 25
#define VELOCIDAD_SALTO_ALTO 50
#define SALTO_ALTO 0
#define TIEMPO_MOVER 500

enum estados{MURIENDO, DISPARANDO, RESPAWNEANDO, CORRIENDO, SALTANDO,
		IDLE, ESCALANDO};

StrategyMoverRingman::StrategyMoverRingman():
velocidad_x(0),
velocidad_y(0),
tiempo_salto(0),
tiempo_mover(0){}

void StrategyMoverRingman::mover(Mapa *mapa, Ringman *pj,
float tiempo){
	tiempo_mover += tiempo;
	bool personaje_en_aire = mapa->esta_en_aire(pj);
	if (personaje_en_aire){
		pj->flotando = true;
	}
	if (!personaje_en_aire){
		pj->flotando = false;
		//Espero para volver a saltar.
		tiempo_salto += tiempo;
		if (pj->activo && tiempo_mover >= TIEMPO_MOVER){
			tiempo_mover = 0;
			perseguir_enemigo(mapa, pj);
		}
	}
	if (pj->flotando){
		velocidad_y -= GRAVEDAD; //valor gravedad.
	}
	if ((tiempo_salto >= TIEMPO_SALTO) && !pj->flotando && pj->activo){
		size_t tipo_salto = rand() % 3;
		velocidad_y += (tipo_salto == SALTO_ALTO)? VELOCIDAD_SALTO_ALTO : VELOCIDAD_SALTO;
		pj->estado_actual = SALTANDO;
		tiempo_salto = 0;
		perseguir_enemigo(mapa, pj);
	}
	actualizar_coordenada(mapa, pj);
}

void StrategyMoverRingman::perseguir_enemigo(Mapa *mapa, Ringman *pj){
	Coordenada c_enemigo = mapa->obtener_coordenada_enemigo(pj);
	int delta_x = c_enemigo.obtener_abscisa()-(pj->coordenada.obtener_abscisa());
	if (delta_x > 0){
		velocidad_x = VELOCIDAD_X;
	}else if (delta_x < 0){ 
		velocidad_x = -VELOCIDAD_X;
	}
}

void StrategyMoverRingman::actualizar_coordenada(Mapa *mapa,
Ringman *pj){
	Coordenada nueva_coordenada = pj->coordenada;
	if (velocidad_x > 0){
		nueva_coordenada = nueva_coordenada.derecha(VELOCIDAD_X);
		pj->estado_actual = CORRIENDO;
	}
	if (velocidad_x < 0){
		nueva_coordenada = nueva_coordenada.izquierda(VELOCIDAD_X);
		pj->estado_actual = CORRIENDO;
	}
	if (velocidad_y > 0){
		nueva_coordenada = nueva_coordenada.arriba(velocidad_y);
	}
	if (velocidad_y < 0){
		nueva_coordenada = nueva_coordenada.abajo(VELOCIDAD_SALTO);
	}
	if (nueva_coordenada == pj->get_coordenada()){
		return;
	}
	if (mapa->puede_ubicarse(pj, nueva_coordenada)){
		pj->coordenada = nueva_coordenada;
		pj->notificar_observadores();
	}else{
		velocidad_x = (velocidad_x != 0)? 0 : velocidad_x;
		velocidad_y = (velocidad_y != 0)? 0 : velocidad_y;
		pj->estado_actual = IDLE;
	}
}

StrategyMoverRingman::~StrategyMoverRingman(){}

