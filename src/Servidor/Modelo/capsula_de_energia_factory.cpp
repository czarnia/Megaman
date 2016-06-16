#include "capsula_de_energia_factory.h"
#include "capsula_de_energia.h"

#include <stdlib.h>

#define PROBABILIDAD_GRANDE 0.05
#define PROBABILIDAD_CHICO 0.1

Premio* Capsula_de_energia_factory::crear(Coordenada c){
  size_t resultado = rand() % 10 + 1;
  if (PROBABILIDAD_GRANDE/PROBABILIDAD_GRANDE+PROBABILIDAD_CHICO < resultado){
    return new Capsula_de_energia(c); //TODO: agregarle a la capsula la cant de su energia.
  }
  return new Capsula_de_energia(c);
}

size_t Capsula_de_energia_factory::probabilidad_de_crear(){
  return PROBABILIDAD_GRANDE + PROBABILIDAD_CHICO;
}
