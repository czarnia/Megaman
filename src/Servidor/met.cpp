#include "met.h"
#include "bala.h"

#define TIEMPO_ATAQUE 2

Met::Met(Mapa *mapa, Coordenada c, std::string id) : Personaje(mapa, c, id){
  tras_escudo = false;
  tiempo_pasado = 0;
}

void Met::atacar(size_t tiempo, Mapa* mapa){
  if (tras_escudo){
    return;
  }
  //llama tres veces al atacar en distintas direcciones
}

void Met::mover(size_t tiempo, Mapa* mapa){ } //el met no se mueve.

void Met::recibir_ataque(Bala* ataque){
  if (tras_escudo){
    return;
  }
  ataque->daniar(this);
}

void Met::update(size_t tiempo){
  tiempo_pasado += tiempo;
  if (tiempo_pasado < TIEMPO_ATAQUE){
    return;
  }
  tras_escudo = !tras_escudo; //cambia al otro estado cada dos segundos.
  Personaje::update(tiempo, mapa);
  tiempo_pasado = 0;
}
