#include "evento_cliente_conectado.h"
#include "../Arquitectura/servidor.h"

void Evento_cliente_conectado::ejecutar(Servidor* s, Log* l){
  s->cliente_conectado();
}
