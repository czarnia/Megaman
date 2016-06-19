#include "updater.h"
#include "mapa.h"

Updater::Updater(Actualizable* act, Mapa* mundo, float tiempo) : up(act),
m(mundo), t(tiempo) {}

void Updater::ejecutar(){
  up->update(t, m);
}

Updater::~Updater(){}
