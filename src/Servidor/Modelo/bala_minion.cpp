#include "bala_minion.h"
#include "personaje.h"
#include "megaman.h"
#include "met.h"
#include "bumby.h"
#include "snipper.h"
#include "jumping_snipper.h"

#define TIEMPO_MOVER 1
#define TIPO_BALA_MINION 11

Bala_minion::Bala_minion(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, TIPO_BALA_MINION, id){}

Bala_minion::~Bala_minion() {}

void Bala_minion::update(size_t tiempo, Mapa* mapa) {
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
		mapa->quitar_bala(this);
	}
}

void Bala_minion::daniar(Personaje* pj) {
	pj->perder_vida(0); //sólo le saca vida a megaman.
}

void Bala_minion::daniar(Megaman* mega) {
	mega->perder_vida(20);
}

void Bala_minion::daniar(Met* met) {
	met->perder_vida(0);
}

void Bala_minion::daniar(Bumby* b){
	b->perder_vida(0);
}

void Bala_minion::daniar(Snipper* s){
	s->perder_vida(0);
}

void Bala_minion::daniar(Jumping_snipper* js){
	js->perder_vida(0);
}

bool Bala_minion::dania_con_escudo(Met* m){
	return false;
}

bool Bala_minion::dania_con_escudo(Snipper* s){
	return false;
}

bool Bala_minion::dania_con_escudo(Jumping_snipper* js){
	return false;
}
