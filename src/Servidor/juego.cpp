#include <cstddef>
#include <iosfwd>

#include "juego.h"
#include "../Comun/lock.h"

Juego::Juego(size_t tamanio) : mundo(tamanio){}

Juego::~Juego(){}

void Juego::update(size_t tiempo){}
