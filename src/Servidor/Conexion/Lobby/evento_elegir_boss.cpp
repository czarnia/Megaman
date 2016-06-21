#include "evento_elegir_boss.h"
#include "../Arquitectura/servidor.h"
#include "../Arquitectura/log.h"

void Evento_elegir_boss::ejecutar(Servidor* s){
  Log::instancia()->inicio_nivel(boss);
  s->empezar_nivel(boss);
}
