#include "procesador_eventos.h"
#include "creador_atacar.h"
#include "creador_mover.h"
#include "creador_cambiar_arma.h"
#include <vector>

Procesador_eventos::Procesador_eventos(int id_procesador) : id(id_procesador){
  generar_creadores();
}

Evento* Procesador_eventos::crear_evento(std::vector<int> mir){
  if (mir.size() != 2){
    return NULL; //TODO: implementar excepcion.
  }
  int comando = mir[0];
  int parametro = mir[1];

  Evento* e = creadores[comando-1]->crear(parametro); //TODO: if comando-1
  // < 0, lanzar excepcion.

  return e;
}

void Procesador_eventos::generar_creadores(){
  creadores.push_back(new Creador_atacar(id));
  creadores.push_back(new Creador_mover(id));
  creadores.push_back(new Creador_cambiar_arma(id));
}
