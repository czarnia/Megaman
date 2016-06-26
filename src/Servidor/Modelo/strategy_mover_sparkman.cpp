#include "strategy_mover_sparkman.h"
#include "sparkman.h"

#define TIEMPO_SALTO 400
#define GRAVEDAD 5
#define VELOCIDAD_Y 40
#define VELOCIDAD_X 6
#define VELOCIDAD_SALTO 25

enum estados{MURIENDO, DISPARANDO, RESPAWNEANDO, CORRIENDO, SALTANDO,
		IDLE, ESCALANDO};

StrategyMoverSparkman::StrategyMoverSparkman():
velocidad_x(0),
velocidad_y(0),
tiempo_salto(0){}

void StrategyMoverSparkman::mover(Mapa *mapa, Sparkman *pj,
float tiempo){
	bool personaje_en_aire = mapa->esta_en_aire(pj);
	if (personaje_en_aire){
		pj->flotando = true;
	}
	if (!personaje_en_aire){
		pj->flotando = false;
		//Espero para volver a saltar.
		tiempo_salto += tiempo;
		if (pj->activo){
			perseguir_enemigo(mapa, pj);
		}
	}
	if (pj->flotando){
		velocidad_y -= GRAVEDAD; //valor gravedad.
	}
	if ((tiempo_salto >= TIEMPO_SALTO) && !pj->flotando && pj->activo){
		velocidad_y += VELOCIDAD_Y;
		pj->estado_actual = SALTANDO;
		tiempo_salto = 0;
		perseguir_enemigo(mapa, pj);
	}
	actualizar_coordenada(mapa, pj);
}

void StrategyMoverSparkman::perseguir_enemigo(Mapa *mapa, Sparkman *pj){
	Coordenada c_enemigo = mapa->obtener_coordenada_enemigo(pj);
	int delta_x = c_enemigo.obtener_abscisa()-(pj->coordenada.obtener_abscisa());
	if (delta_x > 0){
		velocidad_x = VELOCIDAD_X;
	}else if (delta_x < 0){ 
		velocidad_x = -VELOCIDAD_X;
	}
}

void StrategyMoverSparkman::actualizar_coordenada(Mapa *mapa,
Sparkman *pj){
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
		nueva_coordenada = nueva_coordenada.arriba(VELOCIDAD_SALTO);
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

StrategyMoverSparkman::~StrategyMoverSparkman(){}
