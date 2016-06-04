#include "creador_cambiar_arma.h"
#include "evento_cambiar_arma.h"

Creador_cambiar_arma::Creador_cambiar_arma(int id_creador) : id(id_creador) {}

Creador_cambiar_arma::~Creador_cambiar_arma() {}

Evento* Creador_cambiar_arma::crear(int parametro){
  Evento_cambiar_arma* e = new Evento_cambiar_arma(id, parametro);
  return e;
}
