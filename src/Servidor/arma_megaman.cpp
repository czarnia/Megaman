#include "arma_megaman.h"
#include "bala_normal.h"

Bala* Arma_megaman::atacar() {
  return new Bala_normal();
}

Arma_megaman::~Arma_megaman() {}
