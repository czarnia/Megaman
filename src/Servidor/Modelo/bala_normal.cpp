#include "bala_normal.h"
#include "personaje.h"

#define TIEMPO_MOVER 1
#define TIPO_BALA_NORMAL 2

Bala_normal::Bala_normal(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, TIPO_BALA_NORMAL, id){}

Bala_normal::~Bala_normal() {}

void Bala_normal::update(size_t tiempo, Mapa* mapa) {
	Bala::update(tiempo, mapa);
}

void Bala_normal::daniar(Personaje* pj) {
	pj->perder_vida(-1); //le saca una vida
}

void Bala_normal::daniar(Megaman* mega) {
	mega->perder_vida(0); //es una bala de megaman, no puede lastimarse a si mismo.
}

void Bala_normal::daniar(Met* met) {
	met->perder_vida(-1); //el met tiene una sóla vida.
}
