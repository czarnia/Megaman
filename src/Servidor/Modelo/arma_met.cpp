#include "arma_met.h"
#include "bala_met.h"

Arma_met::Arma_met(Factory_observador_ubicable *fact_ubicables):
Arma(fact_ubicables){}

Bala* Arma_met::atacar(int dir_x, int dir_y, Coordenada c) {
  Bala *bullet = new Bala_met(dir_x, dir_y, c, balas_creadas);
  balas_creadas++;
  return bullet;
}

Arma_met::~Arma_met() {}
