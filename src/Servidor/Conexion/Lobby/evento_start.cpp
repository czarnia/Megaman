#include "evento_start.h"
#include "../Arquitectura/servidor.h"
#include "../Arquitectura/log.h"

void Evento_start::ejecutar(Servidor* s){
  Log::instancia()->inicio_juego();
  s->cerrar_conexiones();
  s->empezar_partida();
}
