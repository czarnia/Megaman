#include "evento_elegir_boss.h"
#include "../Arquitectura/servidor.h"
#include "../Arquitectura/log.h"

void Evento_elegir_boss::ejecutar(Servidor* s){
  Log::instancia()->inicio_nivel(boss); //TODO: deshardcodear.
  s->empezar_nivel(boss); //TODO: pasar aca el nivel.
}
