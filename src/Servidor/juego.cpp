#include <cstddef>
#include <iosfwd>

#include "juego.h"
#include "../Comun/lock.h"

Juego::Juego(size_t tamanio) : mundo(tamanio){}

Juego::~Juego(){}

void Juego::update(size_t tiempo){
  /*
  std::vector<Actualizable*> actualizables = mundo.obtener_actualizables();
  for (size_t i = 0; i < actualizables.size(); i++){
    actualizables[i]->update(tiempo);
  }
  */
}

void Juego::personaje_atacar(std::string id_pj, StrategyMover* direccion){
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.atacar(mundo, direccion);
  */
}

void Juego::personaje_mover(std::string id_pj, StrategyMover* direccion){
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.mover(mundo, direccion);
  */
}

void Juego::personaje_cambiar_arma(std::string id_pj, int arma){
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.cambiar_arma(arma);
  */
}
