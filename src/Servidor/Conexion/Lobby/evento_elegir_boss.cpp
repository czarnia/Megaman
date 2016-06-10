#include "evento_elegir_boss.h"
#include "../Arquitectura/servidor.h"

void Evento_elegir_boss::ejecutar(Servidor* s){
  s->empezar_partida(); //cambiar a empezar_nivel.
}
