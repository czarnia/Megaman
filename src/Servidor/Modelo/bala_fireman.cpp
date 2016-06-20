#include "bala_fireman.h"
#include "personaje.h"
#include "personaje_pc.h"
#include "personaje_npc.h"
#include "megaman.h"
#include "met.h"
#include "bumby.h"
#include "snipper.h"
#include "jumping_snipper.h"
#include "bombman.h"
#include "ringman.h"
#include "sparkman.h"
#include "magnetman.h"
#include "fireman.h"

#define TIEMPO_MOVER 1
#define TIPO_BALA_FIREMAN 34
#define PERDIDA_VIDA_BOSS 10
#define VELOCIDAD_X 2
#define VELOCIDAD_Y 2

Bala_fireman::Bala_fireman(int dir_x, int dir_y, Coordenada c, int id):
Bala_especial(dir_x, dir_y, c, TIPO_BALA_FIREMAN, id){
	equipo_pc = false;
}

Bala_fireman::~Bala_fireman() {}
/*
void Bala_fireman::update(float tiempo, Mapa* mapa) {
	Coordenada nueva_coordenada = coord;
	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_MOVER){
		return;
	}
	if (direccion_x > 0){
		nueva_coordenada = nueva_coordenada.derecha(VELOCIDAD_X);
    }
	if (direccion_x < 0){
		nueva_coordenada = nueva_coordenada.izquierda(VELOCIDAD_X);
    }
	if (direccion_y < 0){
		nueva_coordenada = nueva_coordenada.arriba(VELOCIDAD_Y);
	}
	if (direccion_y > 0){
		nueva_coordenada = nueva_coordenada.abajo(VELOCIDAD_Y);
	}

	if (mapa->puede_ubicarse(this, nueva_coordenada)){
		coord = nueva_coordenada;
	}else{
		//TODO: Mover al mapa.
		mapa->quitar_bala(this);
	}
}
*/
void Bala_fireman::daniar(Personaje* pj) {
	pj->perder_vida(0); //sólo le saca vida a megaman.
}

void Bala_fireman::daniar(Megaman* mega) {
	mega->perder_vida(20);
}


void Bala_fireman::daniar(Bombman* b){
	b->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_fireman::daniar(Sparkman* s){
	s->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_fireman::daniar(Magnetman* m){
	m->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_fireman::daniar(Ringman* r){
	r->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_fireman::daniar(Fireman* f){}

void Bala_fireman::daniar(Met* met) {
	met->perder_vida(0);
}

void Bala_fireman::daniar(Bumby* b){
	b->perder_vida();
}

void Bala_fireman::daniar(Snipper* s){
	if (!s->esta_bajo_escudo()){
		s->perder_vida();
	}else{
		s->perder_vida(50);
	}
}

bool Bala_fireman::dania_con_escudo(Met* m){
	return false;
}

bool Bala_fireman::dania_con_escudo(Snipper* s){
	return true;
}

bool Bala_fireman::dania_con_escudo(Jumping_snipper* js){
	return true;
}
