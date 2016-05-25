#include "evento_mover.h"
#include <sstream>

typedef enum {ARRIBA, ABAJO, DERECHA, IZQUIERDA} Direccion;

Evento_mover::Evento_mover(int id_personaje, int dir) : direccion(dir){
	std::stringstream	s;
	s << "megaman" << id_personaje;
	std::string id(s.str());
  	mis_direcciones[ARRIBA] = "ARRIBA";
	mis_direcciones[ABAJO] = "ABAJO";
	mis_direcciones[DERECHA] = "DERECHA";
	mis_direcciones[IZQUIERDA] = "IZQUIERDA";
}

std::string Evento_mover::get_direccion(){
	return mis_direcciones[direccion];
}

void Evento_mover::ejecutar(Juego j){
	
}

Evento_mover::~Evento_mover() {}
