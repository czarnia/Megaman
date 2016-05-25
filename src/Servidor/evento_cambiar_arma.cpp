#include "evento_cambiar_arma.h"
#include <sstream>

Evento_cambiar_arma::Evento_cambiar_arma(int id, int arma) : num_arma(arma){
  std::stringstream	s;
  s << "megaman" <<id;
  id_evento = s.str();
}

Evento_cambiar_arma::~Evento_cambiar_arma() {}

void Evento_cambiar_arma::ejecutar(Juego j){}
