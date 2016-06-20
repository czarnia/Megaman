#include "strategy_mover_fireman.h"
#include "fireman.h"

#define TIEMPO_SALTO 3.5
#define GRAVEDAD 5
#define VELOCIDAD_Y 20
#define VELOCIDAD_X 20

StrategyMoverFireman::StrategyMoverFireman():
velocidad_x(0),
velocidad_y(0),
tiempo_salto(0){}

void StrategyMoverFireman::mover(Mapa *mapa, Fireman *pj, float tiempo){
	bool personaje_flotando = pj->flotando;
	bool personaje_en_aire = mapa->esta_en_aire(pj);
	Coordenada nueva_coordenada = pj->coordenada;
	if (!personaje_flotando && personaje_en_aire){
		pj->flotando = true;
	}
	if (!personaje_en_aire){
		pj->flotando = false;
		velocidad_y = 0;
	}
	if (!pj->flotando){
		//Espero para volver a saltar.
		tiempo_salto += tiempo;
		velocidad_y -= GRAVEDAD; //valor gravedad.
	}
	if ((tiempo_salto >= TIEMPO_SALTO) && !pj->flotando){
		velocidad_y += VELOCIDAD_Y;
		tiempo_salto = 0;
		Coordenada c_enemigo = mapa->obtener_coordenada_enemigo(pj);
		int delta_x = c_enemigo.obtener_abscisa()-(pj->coordenada.obtener_abscisa());
		if (delta_x > 0){
			velocidad_x = VELOCIDAD_X;
		}else if (delta_x < 0){ //Si justo es 0 estan la misma posicion!
			velocidad_x = -VELOCIDAD_X;
		}
	}
	if (velocidad_y > 0){
		nueva_coordenada = nueva_coordenada.arriba(velocidad_y);
	}
	if (velocidad_y < 0){
		nueva_coordenada = nueva_coordenada.abajo(-velocidad_y);
	}
	if (velocidad_x > 0){
		nueva_coordenada = nueva_coordenada.derecha(velocidad_x);
	}
	if (velocidad_x < 0){
		nueva_coordenada = nueva_coordenada.izquierda(-velocidad_x);
	}
	if (!(nueva_coordenada == pj->get_coordenada())){
		actualizar_coordenada(mapa, pj, &nueva_coordenada);
	}
}

void StrategyMoverFireman::actualizar_coordenada(Mapa *mapa,
Fireman *pj, Coordenada *coord){
	if (mapa->puede_ubicarse(pj, *coord)){
		pj->coordenada = *coord;
		pj->notificar_observadores();
	}else{
		velocidad_x = (velocidad_x != 0)? 0 : velocidad_x;
		velocidad_y = (velocidad_y != 0)? 0 : velocidad_y;
	}
}

StrategyMoverFireman::~StrategyMoverFireman(){}
