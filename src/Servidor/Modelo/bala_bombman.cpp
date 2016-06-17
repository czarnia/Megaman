#include "bala_bombman.h"
#include "personaje.h"
#include "megaman.h"
#include "met.h"
#include "bumby.h"
#include "snipper.h"
#include "jumping_snipper.h"

#define TIEMPO_MOVER 1
#define TIPO_BALA_FIREMAN 30

Bala_bombman::Bala_bombman(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, TIPO_BALA_FIREMAN, id){}

Bala_bombman::~Bala_bombman() {}

void Bala_bombman::update(size_t tiempo, Mapa* mapa) {
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
    if (mapa->esta_en_aire(this->coord, this->alto)){
      direccion_y += 1;                    //es una bomba y cae por su peso.
    }
	}else{
		//TODO: Mover al mapa.
		mapa->quitar_bala(this);
	}
}

void Bala_bombman::daniar(Personaje* pj) {
	pj->perder_vida(0); //sólo le saca vida a megaman.
}

void Bala_bombman::daniar(Megaman* mega) {
	mega->perder_vida(50); //le saca media vida al megaman
}

void Bala_bombman::daniar(Met* met) {
	met->perder_vida();
}

void Bala_bombman::daniar(Bumby* b){
	b->perder_vida();
}

void Bala_bombman::daniar(Snipper* s){
	s->perder_vida();
}
/*
void Bala_bombman::daniar(Jumping_snipper* js){
	js->perder_vida();
}*/

bool Bala_bombman::dania_con_escudo(Met* m){
	return true;
}

bool Bala_bombman::dania_con_escudo(Snipper* s){
	return false;
}

bool Bala_bombman::dania_con_escudo(Jumping_snipper* js){
	return false;
}
