#include "evento_cambiar_arma.h"
#include "../../Modelo/juego.h"
#include <sstream>
#include <string>
#include <iostream>

Evento_cambiar_arma::Evento_cambiar_arma(int id, int arma):
id_evento(id),
num_arma(arma){}

Evento_cambiar_arma::~Evento_cambiar_arma() {}

void Evento_cambiar_arma::ejecutar(Juego* j, Log* l){
  std::cout << "cambio el arma a " << num_arma << "\n";
  l->jugador_cambiar_arma(id_evento, num_arma);
  //j->cambiar_arma(id_evento, num_arma);
}
