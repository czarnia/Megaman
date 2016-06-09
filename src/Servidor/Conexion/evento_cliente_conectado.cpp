#include "evento_cliente_conectado.h"
#include "servidor.h"

void Evento_cliente_conectado::ejecutar(Servidor* s){
  s->cliente_conectado();
}
