#include "celda.h"

Celda(){
  ocupada = false;
}

void ubicar(Ubicable ocupa){
  if (ocupada){
    return //se podria lanzar una excepcion tambien...
  }
  ocupante = ocupa;
  ocupada = true;
}

Ubicable desocupar(){
  if (!ocupada){
    return NULL; //TODO: agregar excepcion.
  }
  ocupada = false;
  return ubicable;
}

Ubicable obtener_ubicable(){
  if (!ocupada){
    return NULL;
  }
  return ubicable;
}

bool esta_ocupada(){
  return ocupada;
}
