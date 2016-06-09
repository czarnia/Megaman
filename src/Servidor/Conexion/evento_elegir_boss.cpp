#include "evento_elegir_boss.h"
#include "servidor.h"

void Evento_elegir_boss::ejecutar(Servidor* s){
  s->empezar_partida(); //cambiar a empezar_nivel.
}
