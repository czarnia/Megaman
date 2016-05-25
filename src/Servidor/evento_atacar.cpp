#include "evento_atacar.h"
#include <sstream>

Evento_atacar::Evento_atacar(int id, int dir) : direccion(dir){
  std::stringstream	s;
  s << "megaman" <<id;
  id_evento = s.str();
}

Evento_atacar::~Evento_atacar() {}

void Evento_atacar::ejecutar(Juego j){}
