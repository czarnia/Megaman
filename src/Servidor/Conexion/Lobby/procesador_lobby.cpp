#include "procesador_lobby.h"
#include "creador_start.h"
#include "creador_elegir_boss.h"

#include "evento_null_lobby.h"

#include <vector>

#define COMANDO_MINIMO 5

Procesador_lobby::Procesador_lobby(int id_procesador) : id(id_procesador){
  generar_creadores();
}

Evento_lobby* Procesador_lobby::crear_evento(int comando, int parametro){
  if ((comando-COMANDO_MINIMO > creadores.size()) || (comando-COMANDO_MINIMO < 0)){
    Evento_lobby* e = new Evento_null_lobby();
    return e;
  }
  Evento_lobby* e = creadores[comando-COMANDO_MINIMO]->crear(parametro);
  return e;
}

void Procesador_lobby::generar_creadores(){
  creadores.push_back(new Creador_start(id));
  creadores.push_back(new Creador_elegir_boss(id));;
}
