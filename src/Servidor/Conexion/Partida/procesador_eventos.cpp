#include "procesador_eventos.h"
#include "creador_atacar.h"
#include "creador_mover.h"
#include "creador_parar.h"
#include "creador_cambiar_arma.h"

#include "evento_null_partida.h"

#include <vector>
#include <string>

Procesador_eventos::Procesador_eventos(int id_procesador) : id(id_procesador){
  generar_creadores();
}

Evento* Procesador_eventos::crear_evento(int comando, int parametro){
  if ((comando-1 > creadores.size()) || (comando-1 < 0)){
    Evento* e = new Evento_null_partida();
    return e;
  }
  Evento* e = creadores[comando-1]->crear(parametro);
  return e;
}

void Procesador_eventos::generar_creadores(){
  creadores.push_back(new Creador_atacar(id));
  creadores.push_back(new Creador_mover(id));
  creadores.push_back(new Creador_parar(id));
  creadores.push_back(new Creador_cambiar_arma(id));
}
