#include "evento_cliente_desconectado.h"
#include "../Arquitectura/servidor.h"

void Evento_cliente_desconectado::ejecutar(Servidor* s, Log* l){
  l->cliente_desconectado(id);
  s->cliente_desconectado(id);
}
