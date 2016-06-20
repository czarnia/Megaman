#include "bala_minion.h"
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
#define TIPO_BALA_MINION 36
#define PERDIDA_VIDA_BOSS 10

Bala_minion::Bala_minion(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, TIPO_BALA_MINION, id){}

Bala_minion::~Bala_minion() {}

void Bala_minion::update(float tiempo, Mapa* mapa){
	Bala::update(tiempo, mapa);
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

void Bala_minion::daniar(Bombman* b){
	b->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_minion::daniar(Sparkman* s){
	s->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_minion::daniar(Magnetman* m){
	m->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_minion::daniar(Ringman* r){
	r->perder_vida(PERDIDA_VIDA_BOSS);
}

void Bala_minion::daniar(Fireman* f){
	f->perder_vida(PERDIDA_VIDA_BOSS);
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

bool Bala_minion::dania(Personaje_pc* pj){
	return true;
}

bool Bala_minion::dania(Personaje_npc* pj){
	return false;
}
