#include <cstddef>
#include <iosfwd>

#include "juego.h"
#include "../Comun/lock.h"

#define TIEMPO 5

Juego::Juego(Servidor *s, size_t tamanio): 
mundo(s, tamanio){
  fin_partida = false;
}

Juego::~Juego(){}

void Juego::jugar(){
  while (!fin_partida){
    update(TIEMPO);
  }
}

void Juego::terminar_partida(){
  fin_partida = true;
}

void Juego::update(size_t tiempo){
  /*
  std::vector<Actualizable*> actualizables = mundo.obtener_actualizables();
  for (size_t i = 0; i < actualizables.size(); i++){
    actualizables[i]->update(tiempo, mapa);
  }
  */
}

void Juego::personaje_atacar(std::string id_pj){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.atacar(mundo, direccion);
  */
}

void Juego::personaje_mover(std::string id_pj){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.mover(mundo, direccion);
  */
}

void Juego::personaje_cambiar_arma(std::string id_pj, int arma){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.cambiar_arma(arma);
  */
}
