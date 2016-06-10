#include "evento_start.h"
#include "../Arquitectura/servidor.h"

void Evento_start::ejecutar(Servidor* s, Log* l){
  l->inicio_juego();
  s->cerrar_conexiones();
}
