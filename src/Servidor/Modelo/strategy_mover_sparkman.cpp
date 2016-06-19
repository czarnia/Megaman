#include "strategy_mover_sparkman.h"
#include "sparkman.h"

#define TIEMPO_SALTO 1
#define GRAVEDAD 5
#define VELOCIDAD_Y 10
#define VELOCIDAD_X 2

StrategyMoverSparkman::StrategyMoverSparkman():
velocidad_x(0),
velocidad_y(0),
tiempo_salto(0){}

void StrategyMoverSparkman::mover(Mapa *mapa, Sparkman *pj,
float tiempo){
	bool personaje_flotando = pj->flotando;
	bool personaje_en_aire = mapa->esta_en_aire(pj);
	if (!personaje_flotando && personaje_en_aire){
		pj->flotando = true;
		velocidad_y += GRAVEDAD; //valor gravedad.
	}
	if (!personaje_en_aire){
		pj->flotando = false;
	}
	if (!pj->flotando){
		//Espero para volver a saltar.
		tiempo_salto += tiempo;
	}
	if ((tiempo_salto >= TIEMPO_SALTO) && !pj->flotando){
		velocidad_y -= VELOCIDAD_Y;
		tiempo_salto -= TIEMPO_SALTO;
		Coordenada c_enemigo = mapa->obtener_coordenada_enemigo(pj);
		int delta_x = c_enemigo.obtener_abscisa()-(pj->coordenada.obtener_abscisa());
		if (delta_x > 0){
			velocidad_x += VELOCIDAD_X;
		}else if (delta_x < 0){ //Si justo es 0 estan la misma posicion!
			velocidad_x -= VELOCIDAD_X;
		}
		aplicar_movimiento(mapa, pj);
	}
}

void StrategyMoverSparkman::aplicar_movimiento(Mapa *mapa, Sparkman *pj){
	Coordenada nueva_coordenada = pj->coordenada;
	if (velocidad_y < 0){
		nueva_coordenada = nueva_coordenada.arriba(VELOCIDAD_Y);
	}
	if (velocidad_y > 0){
		nueva_coordenada = nueva_coordenada.abajo(VELOCIDAD_Y);
		//pj->estado_actual = SALTANDO;
	}
	if (velocidad_x > 0){
		nueva_coordenada = nueva_coordenada.derecha(VELOCIDAD_Y);
	}
	if (velocidad_x < 0){
		nueva_coordenada = nueva_coordenada.izquierda(VELOCIDAD_Y);
	}
	actualizar_coordenada(mapa, pj, &nueva_coordenada);
}

void StrategyMoverSparkman::actualizar_coordenada(Mapa *mapa,
Sparkman *pj, Coordenada *coord){
	if (mapa->puede_ubicarse(pj, *coord)){
		pj->coordenada = *coord;
		pj->notificar_observadores();
	}else{
		velocidad_x = (velocidad_x != 0)? 0 : velocidad_x;
		velocidad_y = (velocidad_y != 0)? 0 : velocidad_y;
	}
}

StrategyMoverSparkman::~StrategyMoverSparkman(){}
