#include "manejador_lobby.h"
#include "evento_lobby.h"
#include "../Arquitectura/servidor.h"

Manejador_lobby::Manejador_lobby(Servidor* s) : srv(s){}

Manejador_lobby::~Manejador_lobby() {}

void Manejador_lobby::ejecutar_evento(Evento_lobby* e){
  e->ejecutar(srv);
}
