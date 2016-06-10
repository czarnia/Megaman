#include "evento_mover.h"
#include "../../Modelo/juego.h"
#include <sstream>
#include <string>
#include <iostream>

Evento_mover::Evento_mover(int id, int dir):
id_evento(id),
direccion(dir){}

int Evento_mover::get_direccion(){
	return direccion;
}

void Evento_mover::ejecutar(Juego* j, Log* l){
  std::cout << "me muevo en direcion " << direccion << "\n";
	l->jugador_mover(id_evento, direccion);
  j->personaje_mover(id_evento, direccion);
}

Evento_mover::~Evento_mover(){}
