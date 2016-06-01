#include "bala_normal.h"

#define TIEMPO_MOVER 1

Bala_normal::Bala_normal(int dir_x, int dir_y):
Bala(dir_x, dir_y){}

Bala_normal::~Bala_normal() {}

void Bala_normal::update(size_t tiempo, Mapa* mapa) { 
	Coordenada nueva_coordenada(-1, -1);
	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_MOVER){
		return;
	}
	if (direccion_x > 0){
		nueva_coordenada = nueva_coordenada.derecha(2);
    }
	if (direccion_x < 0){
		nueva_coordenada = nueva_coordenada.izquierda(2);
    }
	if (direccion_y < 0){
		nueva_coordenada = nueva_coordenada.arriba(2);
	}
	if (direccion_y > 0){
		nueva_coordenada = nueva_coordenada.abajo(2);
	}

	if (mapa->puede_ubicarse_en(nueva_coordenada, 0, 0)){
		//coordenada = nueva_coordenada;
	}else{
		//TODO: Mover al mapa.
		//mapa->quitar_bala(this); 
	}
}

void Bala_normal::daniar(Personaje* pj) {
	pj->perder_vida(-1); //le saca una vida
}

void Bala_normal::daniar(Megaman* mega) {
	mega->perder_vida(0); //es una bala de megaman, no puede lastimarse a si mismo.
}

void Bala_normal::daniar(Met* met) {
	met->perder_vida(-1); //el met tiene una sóla vida.
}
