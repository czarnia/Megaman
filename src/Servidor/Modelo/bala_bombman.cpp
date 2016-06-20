#include "bala_bombman.h"
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
#define TIEMPO_SUBIDA 3
#define VELOCIDAD_X 2
#define VELOCIDAD_y 2
#define TIPO_BALA_BOMBMAN 30
#define PERDIDA_VIDA_BOSS 10

Bala_bombman::Bala_bombman(int dir_x, int dir_y, Coordenada c, int id):
Bala_especial(dir_x, dir_y, c, TIPO_BALA_FIREMAN, id){
	impacto = false;
	equipo_pc = false;
}

Bala_bombman::~Bala_bombman() {}

void Bala_bombman::update(float tiempo, Mapa* mapa) {
	if (impacto){
		mapa->quitar_bala(this);
		coord = Coordenada(-1, -1);
		notificar_observadores();
	}
	Coordenada nueva_coordenada = coord;
	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_MOVER){
		return;
	}
	if (tiempo_pasado < TIEMPO_SUBIDA){
		//Sube:
		nueva_coordenada = nueva_coordenada.arriba(VELOCIDAD_y);
	}else{
		//Cae:
		nueva_coordenada = nueva_coordenada.abajo(VELOCIDAD_y);
	}
	if (direccion_x > 0){
		nueva_coordenada = nueva_coordenada.derecha(VELOCIDAD_X);
	}
	if (direccion_x < 0){
		nueva_coordenada = nueva_coordenada.izquierda(VELOCIDAD_X);
    }

	impacto = !mapa->puede_ubicarse(this, nueva_coordenada) ||
				mapa->bala_colisiona_con_pj(this, &nueva_coordenada);
	if (mapa->puede_ubicarse(this, nueva_coordenada)){
		coord = nueva_coordenada;
		notificar_observadores();
	}
}

void Bala_bombman::daniar(Personaje* pj) {
	//sólo le saca vida a megaman.
	pj->perder_vida(0);
}

void Bala_bombman::daniar(Megaman* mega) {
	//le saca media vida al megaman
	mega->perder_vida(50);
}

void Bala_bombman::daniar(Bombman* b){}

void Bala_bombman::daniar(Sparkman* s){
	s->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_bombman::daniar(Magnetman* m){
	m->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_bombman::daniar(Ringman* r){
	r->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_bombman::daniar(Fireman* f){
	f->perder_vida(PERDIDA_VIDA_BOSS);
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

bool Bala_bombman::dania_con_escudo(Met* m){
	return true;
}

bool Bala_bombman::dania_con_escudo(Snipper* s){
	return false;
}

bool Bala_bombman::dania_con_escudo(Jumping_snipper* js){
	return false;
}
