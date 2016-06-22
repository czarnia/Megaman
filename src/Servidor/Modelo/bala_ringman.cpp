#include "bala_ringman.h"
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
#define TIPO_BALA_RINGMAN 33
#define PERDIDA_VIDA_BOSS 10
#define PERDIDA_VIDA_MEGA 20
#define TIEMPO_REBOTE 10
#define VELOCIDAD_X 2
#define VELOCIDAD_Y 2

Bala_ringman::Bala_ringman(int dir_x, int dir_y, Coordenada c, int id):
Bala_especial(dir_x, dir_y, c, TIPO_BALA_RINGMAN, id){
	equipo_pc = false;
}

Bala_ringman::~Bala_ringman() {}

void Bala_ringman::update(float tiempo, Mapa* mapa) {
	if (impacto){
		mapa->quitar_bala(this);
	}

	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_MOVER){
		return;
	}		
	if(tiempo_pasado >= TIEMPO_REBOTE){
		impacto = true;
		direccion_x = 0;
		direccion_y = 0;
		return;
	}
	int delta_x = 0, delta_y = 0;
	delta_x = (direccion_x > 0)? VELOCIDAD_X : -VELOCIDAD_X;
	delta_y = (direccion_y > 0)? -VELOCIDAD_Y : VELOCIDAD_Y;
	Coordenada nueva_coordenada = coord;
	Coordenada coord_rebote_x = coord;
	Coordenada coord_rebote_y = coord;
	Coordenada coord_rebote = coord;
	//REFACTOREAR ESTO...
	if (mapa->puede_ubicarse(this, nueva_coordenada)){
		coord = nueva_coordenada;
	}else{ 
		coord_rebote_y.sumar_abscisa(delta_x);
		if(mapa->puede_ubicarse(this, coord_rebote_y)){
			direccion_y = -direccion_y;
			coord = coord_rebote_y;
		}else{ 
			coord_rebote_x.sumar_ordenada(delta_y);
			if(mapa->puede_ubicarse(this, coord_rebote_x)){
				direccion_x = -direccion_x;
				coord = coord_rebote_x;
			}else{
				coord_rebote.sumar_abscisa(delta_x);
				coord_rebote.sumar_ordenada(delta_y);
				if(mapa->puede_ubicarse(this, coord_rebote)){
					direccion_x = -direccion_x;
					direccion_y = -direccion_y;
					coord = coord_rebote;
				}
			}
		}
	}
}

void Bala_ringman::daniar(Personaje* pj) {}

void Bala_ringman::daniar(Megaman* mega) {
	mega->perder_vida(PERDIDA_VIDA_MEGA);
}

void Bala_ringman::daniar(Bombman* b){
	b->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_ringman::daniar(Sparkman* s){
	s->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_ringman::daniar(Magnetman* m){
	m->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_ringman::daniar(Ringman* r){}

void Bala_ringman::daniar(Fireman* f){
	f->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_ringman::daniar(Met* met) {}

void Bala_ringman::daniar(Bumby* b){
	b->perder_vida();
}

void Bala_ringman::daniar(Snipper* s){
	if (!s->esta_bajo_escudo()){
		s->perder_vida();
	}else{
		s->perder_vida(50);
	}
}

bool Bala_ringman::dania_con_escudo(Met* m){
	return false;
}

bool Bala_ringman::dania_con_escudo(Snipper* s){
	return true;
}

bool Bala_ringman::dania_con_escudo(Jumping_snipper* js){
	return true;
}
