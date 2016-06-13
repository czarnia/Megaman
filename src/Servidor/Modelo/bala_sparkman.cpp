#include "bala_sparkman.h"
#include "personaje.h"

#define TIEMPO_MOVER 1
#define TIPO_BALA_SPARKMAN 2

Bala_sparkman::Bala_sparkman(int dir_x, int dir_y, Coordenada c, int id):
Bala(dir_x, dir_y, c, TIPO_BALA_SPARKMAN, id){}

Bala_sparkman::~Bala_sparkman() {}

void Bala_sparkman::update(size_t tiempo, Mapa* mapa) {
	Bala::update(tiempo, mapa);
}

void Bala_sparkman::daniar(Personaje* pj) {
	pj->perder_vida(0); //asumo solo daña al megaman.
}

void Bala_sparkman::daniar(Megaman* mega) {
	mega->perder_vida(25);
}

void Bala_sparkman::daniar(Met* met) {
	met->perder_vida(0); //es un boss y como tal no daña a sus minions.
}
