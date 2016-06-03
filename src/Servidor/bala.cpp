#include "bala.h"

#define TIEMPO_MOVER 5
#define VELOCIDAD 4
#define ARRIBA 1
#define ABAJO 2
#define DERECHA 3
#define IZQUIERDA 4

#define AVANZA 1
#define RETROCEDE -1
#define SUBE 1
#define BAJA -1

bool Bala::puede_ocupar(Personaje *pj){
	return true;
}


void Bala::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	size_t delta_x = 0;
	size_t delta_y = 0;
	bool llegue = false;
	Coordenada actual = coord;
	if (tiempo_pasado >= TIEMPO_MOVER){
		while (!llegue){
			if ((direccion_x != 0) && (delta_x != VELOCIDAD)){
				actual = (direccion_x == DERECHA)? actual.derecha() : actual.izquierda();
				delta_x += (direccion_x == DERECHA)? AVANZA : RETROCEDE;
			}
			if ((direccion_y != 0) && (delta_y != VELOCIDAD)){
				actual = (direccion_x == ABAJO)? actual.abajo() : actual.arriba();
				delta_y += (direccion_y == ABAJO)? BAJA : SUBE;
			}
			llegue = !(((direccion_x != 0) && (delta_x != VELOCIDAD)) 
					    || ((direccion_y != 0) && (delta_y != VELOCIDAD)));
					
			if (!llegue){
				llegue = !mapa->puede_ubicarse_en(actual, 0, 0);
				llegue = llegue || mapa->hay_personaje(&actual);
			}
		}
		if (!(actual == coord)){
			coord = actual;
			//notificar cambio posicion
		}else{
			//notificar colision y destruir
		}
	}
}

void Bala::interactuar(Personaje* pj){
	pj->recibir_ataque(this);
}
