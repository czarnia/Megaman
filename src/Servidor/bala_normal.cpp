#include "bala_normal.h"

Bala_normal::~Bala_normal() {}

void Bala_normal::update(size_t tiempo, Mapa* mapa) { /*mover la bala*/ }

void Bala_normal::daniar(Personaje* pj) {
  pj->perder_vida(-1); //le saca una vida
}

void Bala_normal::daniar(Megaman* mega) {
  mega->perder_vida(0); //es una bala de megaman, no puede lastimarse a si mismo.
}

void Bala_normal::daniar(Met* met) {
  met->perder_vida(-1); //el met tiene una sóla vida.
}
