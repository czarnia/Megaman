#include "nueva_vida_factory.h"
#include "nueva_vida.h"

#include <stdlib.h>

#define PROBABILIDAD 0.01

Premio* Nueva_vida_factory::crear(Coordenada c){
  return new Nueva_vida(c);
}

size_t Nueva_vida_factory::probabilidad_de_crear(){
  return PROBABILIDAD;
}
