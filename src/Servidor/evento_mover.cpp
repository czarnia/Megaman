#include "evento_mover.h"

Evento_mover::Evento_mover(int id, int dir) : direccion(dir){
  std::stringstream	s;
  s << "megaman" <<id;
  std::string id(s.str());
}

Evento_mover::~Evento_mover() {}

void Evento_mover::ejecutar(Juego j){}
