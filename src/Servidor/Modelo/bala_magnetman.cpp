#include "bala_magnetman.h"
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
#define VELOCIDAD_X 2
#define VELOCIDAD_Y 2
#define TIPO_BALA_MAGNETMAN 31
#define PERDIDA_VIDA_BOSS 10

Bala_magnetman::Bala_magnetman(int dir_x, int dir_y, Coordenada c, int id):
Bala_especial(dir_x, dir_y, c, TIPO_BALA_MAGNETMAN, id){
	equipo_pc = false;
	impacto = false;
}

Bala_magnetman::~Bala_magnetman() {}

void Bala_magnetman::update(float tiempo, Mapa* mapa) {
	if (impacto){
		mapa->quitar_bala(this);
		coord = Coordenada(-1, -1);
		notificar_observadores();
	}
	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_MOVER){
		return;
	}
	Coordenada nueva_coordenada = coord;
	Coordenada c_enemigo = mapa->obtener_coordenada_enemigo_pc_cercano(this);
	int delta_x = c_enemigo.obtener_abscisa()-(coord.obtener_abscisa());
	int delta_y = c_enemigo.obtener_ordenada()-(coord.obtener_ordenada());
	
	if (delta_x > 0){
		nueva_coordenada = nueva_coordenada.derecha(VELOCIDAD_X);
	}
	if (delta_x < 0){
		nueva_coordenada = nueva_coordenada.izquierda(VELOCIDAD_X);
	}
	if (delta_y > 0){
		nueva_coordenada = nueva_coordenada.arriba(VELOCIDAD_Y);
	}
	if (delta_y < 0){
		nueva_coordenada = nueva_coordenada.abajo(VELOCIDAD_Y);
	}

	impacto = !mapa->puede_ubicarse(this, nueva_coordenada) || 
				mapa->bala_colisiona_con_pj(this, &nueva_coordenada);
	if (mapa->puede_ubicarse(this, nueva_coordenada)){
		coord = nueva_coordenada;
		notificar_observadores();
	}
}

void Bala_magnetman::daniar(Personaje* pj) {
	pj->perder_vida(0); //sólo le saca vida a megaman.
}

void Bala_magnetman::daniar(Megaman* mega) {
	mega->perder_vida(20);
}

void Bala_magnetman::daniar(Met* met) {}

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

void Bala_magnetman::daniar(Bombman* b){
	b->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_magnetman::daniar(Sparkman* s){
	s->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_magnetman::daniar(Magnetman* m){}

void Bala_magnetman::daniar(Ringman* r){
	r->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_magnetman::daniar(Fireman* f){
	f->perder_vida(PERDIDA_VIDA_BOSS);
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
