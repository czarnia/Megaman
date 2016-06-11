#include "evento_elegir_boss.h"
#include "../Arquitectura/servidor.h"
#include "../Arquitectura/log.h"

void Evento_elegir_boss::ejecutar(Servidor* s){
  Log::instancia()->inicio_nivel(1); //TODO: deshardcodear.
  s->empezar_partida(); //cambiar a empezar_nivel.
}
