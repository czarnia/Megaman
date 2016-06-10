#include "evento_start.h"
#include "../Arquitectura/servidor.h"

void Evento_start::ejecutar(Servidor* s){
  s->cerrar_conexiones();
}
