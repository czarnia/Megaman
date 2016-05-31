#include "bala.h"

bool Bala::puede_ocupar(Personaje *pj){
  return true;
}

void Bala::interactuar(Personaje* pj){
  pj->recibir_ataque(this);
}
