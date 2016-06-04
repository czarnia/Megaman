#include "arma_megaman.h"
#include "bala_normal.h"

Arma_megaman::Arma_megaman(){
	balas_creadas = 0;
}

Bala* Arma_megaman::atacar(int dir_x, int dir_y, Coordenada c) {
  Bala *bullet = new Bala_normal(dir_x, dir_y, c, balas_creadas);
  balas_creadas++;
  return bullet;
}

Arma_megaman::~Arma_megaman() {}
