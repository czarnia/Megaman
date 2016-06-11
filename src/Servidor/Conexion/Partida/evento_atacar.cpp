#include "evento_atacar.h"
#include "../../Modelo/juego.h"
#include "../Arquitectura/log.h"
#include <sstream>
#include <string>
#include <iostream>

Evento_atacar::Evento_atacar(int id, int dir):
id_evento(id),
direccion(dir){}

Evento_atacar::~Evento_atacar() {}

void Evento_atacar::ejecutar(Juego* j){
	std::cout << "ataco en direccion " << direccion << "\n";
	Log::instancia()->jugador_atacar(id_evento, direccion);
	j->personaje_atacar(id_evento, direccion);
}
