#include "evento_cliente_desconectado.h"
#include "servidor.h"

void Evento_cliente_desconectado::ejecutar(Servidor* s){
  s->cliente_desconectado(id);
}
