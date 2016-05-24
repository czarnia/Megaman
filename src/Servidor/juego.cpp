#include <cstddef>
#include <iosfwd>

#include "juego.h"

Juego::Juego(size_t tamanio) : mundo(tamanio){}

Juego::~Juego(){}

void Juego::update(size_t tiempo){}

void Juego::procesar_evento(Evento* e){
  e.ejecutar(*this);
}
