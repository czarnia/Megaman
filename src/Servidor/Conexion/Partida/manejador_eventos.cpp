#include "manejador_eventos.h"

Manejador_eventos::Manejador_eventos(Juego *m, Log* lg) : mundo(m), l(lg){}

Manejador_eventos::~Manejador_eventos() {}

void Manejador_eventos::ejecutar_evento(Evento* e){
  e->ejecutar(mundo, l);
}
