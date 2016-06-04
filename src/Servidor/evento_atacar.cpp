#include "evento_atacar.h"
#include "juego.h"
#include <sstream>
#include <string>
#include <iostream>

Evento_atacar::Evento_atacar(int id, int dir): 
id_evento(id),
direccion(dir){}

Evento_atacar::~Evento_atacar() {}

void Evento_atacar::ejecutar(Juego* j){
	std::cout << "ataco en direccion " << direccion << "\n";
	j->personaje_atacar(id_evento, direccion);
}
