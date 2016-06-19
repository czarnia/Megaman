#include "bala_magnetman.h"
#include "personaje.h"
#include "megaman.h"
#include "met.h"
#include "bumby.h"
#include "snipper.h"
#include "jumping_snipper.h"

#define TIEMPO_MOVER 1
#define TIPO_BALA_MAGNETMAN 31

Bala_magnetman::Bala_magnetman(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, TIPO_BALA_MAGNETMAN, id){}

Bala_magnetman::~Bala_magnetman() {}

void Bala_magnetman::update(float tiempo, Mapa* mapa) {
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

void Bala_magnetman::daniar(Personaje* pj) {
	pj->perder_vida(0); //sólo le saca vida a megaman.
}

void Bala_magnetman::daniar(Megaman* mega) {
	mega->perder_vida(20);
}

void Bala_magnetman::daniar(Met* met) {
	met->perder_vida(0);
}

void Bala_magnetman::daniar(Bumby* b){
	b->perder_vida();
}

void Bala_magnetman::daniar(Snipper* s){
	if (!s->esta_bajo_escudo()){
		s->perder_vida();
	}else{
		s->perder_vida(50);
	}
}

bool Bala_magnetman::dania_con_escudo(Met* m){
	return false;
}

bool Bala_magnetman::dania_con_escudo(Snipper* s){
	return true;
}

bool Bala_magnetman::dania_con_escudo(Jumping_snipper* js){
	return true;
}
