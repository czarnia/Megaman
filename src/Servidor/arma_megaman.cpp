#include "arma_megaman.h"
#include "bala_normal.h"

Bala* Arma_megaman::atacar(int dir_x, int dir_y) {
  return new Bala_normal(dir_x, dir_y);
}

Arma_megaman::~Arma_megaman() {}
