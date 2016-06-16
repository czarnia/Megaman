#include "capsula_de_plasma_factory.h"
#include "capsula_de_plasma.h"

#include <stdlib.h>

#define PROBABILIDAD_GRANDE 0.05
#define PROBABILIDAD_CHICO 0.1

#define TIPO_CAPSULA_CHICA 16
#define TIPO_CAPSULA_GRANDE 17

Premio* Capsula_de_plasma_factory::crear(Coordenada c){
  size_t resultado = rand() % 10 + 1;
  if (PROBABILIDAD_GRANDE/PROBABILIDAD_GRANDE+PROBABILIDAD_CHICO < resultado){
    return new Capsula_de_plasma(c, TIPO_CAPSULA_GRANDE);
  }
  return new Capsula_de_plasma(c, TIPO_CAPSULA_CHICA);
}

size_t Capsula_de_plasma_factory::probabilidad_de_crear(){
  return PROBABILIDAD_GRANDE + PROBABILIDAD_CHICO;
}
