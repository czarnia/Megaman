#include "evento_atacar.h"

Evento_atacar::Evento_atacar(int id, int dir) : direccion(dir){
  std::stringstream	s;
  s << "megaman" <<id;
  std::string id(s.str());
}

Evento_atacar::~Evento_atacar() {}

void Evento_atacar::ejecutar(Juego j){}
