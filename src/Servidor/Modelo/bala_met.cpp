#include "bala_met.h"
#include "personaje.h"

#define TIEMPO_MOVER 1

Bala_met::Bala_met(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, id){}

Bala_met::~Bala_met() {}

void Bala_met::update(size_t tiempo, Mapa* mapa) {
	Coordenada nueva_coordenada = coord;
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

	if (mapa->puede_ubicarse(this, nueva_coordenada)){
		coord = nueva_coordenada;
	}else{
		//TODO: Mover al mapa.
		//mapa->quitar_bala(this);
	}
}

void Bala_met::daniar(Personaje* pj) {
	pj->perder_vida(0); //sólo le saca vida a megaman.
}

void Bala_met::daniar(Megaman* mega) {
	mega->perder_vida(0.2);
}

void Bala_met::daniar(Met* met) {
	met->perder_vida(0);
}
