#include "evento_parar.h"
#include "../Modelo/juego.h"
#include <sstream>
#include <string>
#include <iostream>

Evento_parar::Evento_parar(int id, int dir) : direccion(dir){
	std::stringstream	s;
	s << "megaman" <<id;
	id_evento = s.str();
}

int Evento_parar::get_direccion(){
	return direccion;
}

void Evento_parar::ejecutar(Juego* j){
  std::cout << "EVENTO: pare de moverme\n";
  j->personaje_parar(id_evento, direccion);
}

Evento_parar::~Evento_parar(){}
