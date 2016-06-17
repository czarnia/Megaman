#include "bala_normal.h"
#include "personaje.h"
#include "megaman.h"
#include "met.h"
#include "bumby.h"
#include "snipper.h"
#include "jumping_snipper.h"

#define TIEMPO_MOVER 1
#define TIPO_BALA_NORMAL 35

Bala_normal::Bala_normal(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, TIPO_BALA_NORMAL, id){}

Bala_normal::~Bala_normal() {}

void Bala_normal::update(size_t tiempo, Mapa* mapa) {
	Bala::update(tiempo, mapa);
}

void Bala_normal::daniar(Personaje* pj) {
	pj->perder_vida(); //le saca una vida
}

void Bala_normal::daniar(Megaman* mega) {
	mega->perder_vida(0); //es una bala de megaman, no puede lastimarse a si mismo.
}

void Bala_normal::daniar(Met* met) {
	met->perder_vida(); //el met tiene una sóla vida.
}

void Bala_normal::daniar(Bumby* b){
	b->perder_vida();
}

void Bala_normal::daniar(Snipper* s){
	s->perder_vida(50);
}

void Bala_normal::daniar(Jumping_snipper* js){
	js->perder_vida(50);
}

bool Bala_normal::dania_con_escudo(Met* m){
	return false;
}

bool Bala_normal::dania_con_escudo(Snipper* s){
	return false;
}

bool Bala_normal::dania_con_escudo(Jumping_snipper* js){
	return false;
}
