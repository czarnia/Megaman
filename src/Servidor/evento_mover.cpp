#include "evento_mover.h"
#include <sstream>

Evento_mover::Evento_mover(int id, int dir) : direccion(dir){
	std::stringstream	s;
	s << "megaman" <<id;
	id_evento = s.str();
}

int Evento_mover::get_direccion(){
	return direccion;
}

void Evento_mover::ejecutar(Juego j){
	
}

Evento_mover::~Evento_mover() {}
