#include "creador_cambiar_arma.h"

Evento* Creador_cambiar_arma::crear(int parametro){
  Evento* e = new Evento_cambiar_arma(id, parametro);
  return e;
}
