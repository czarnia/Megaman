#include "evento_cambiar_arma.h"
#include <sstream>
#include <string>
#include <iostream>

Evento_cambiar_arma::Evento_cambiar_arma(int id, int arma) : num_arma(arma){
  std::stringstream	s;
  s << "megaman" <<id;
  id_evento = s.str();
}

Evento_cambiar_arma::~Evento_cambiar_arma() {}

void Evento_cambiar_arma::ejecutar(Juego j){
  std::cout << "cambio el arma a " << num_arma << "\n";
  j.cambiar_arma(id_evento, arma);
}
