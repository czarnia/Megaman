#include "evento_cambiar_arma.h"
#include <sstream>
#include <string>
#include <iostream>

Evento_cambiar_arma::Evento_cambiar_arma(int id, int arma) : 
num_arma(arma){
  std::stringstream	s;
  s << "megaman" <<id;
  id_evento = s.str();
}

Evento_cambiar_arma::~Evento_cambiar_arma() {}

void Evento_cambiar_arma::ejecutar(Juego *j){
  std::cout << "cambio el arma a " << num_arma << "\n";
<<<<<<< HEAD
  //j.cambiar_arma(id_evento, arma);
=======
  //j->cambiar_arma(id_evento, num_arma);
>>>>>>> e85b7f45fec39255dd1de94f1b2bec9c3956dae0
}
