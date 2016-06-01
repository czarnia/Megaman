#include "met.h"
#include "bala.h"

#define TIEMPO_ATAQUE 2

Met::Met(Mapa *mapa, Coordenada c, std::string id) : Personaje(mapa, c, id){
  tras_escudo = false;
  tiempo_pasado = 0;
}

void Met::atacar(size_t tiempo, int dir, Mapa* mapa){
	if (tras_escudo){
		return;
	}
	Bala *bala1, *bala2, *bala3;
	Coordenada pos_inicial = coordenada.izquierda(ancho/2);
	//el met no tiene armas(?)
	//bala1 = armas[arma_act-1]->atacar(-1, 0);
	//bala2 = armas[arma_act-1]->atacar(-1, 1);
	//bala3 = armas[arma_act-1]->atacar(-1, -1);
	mapa->agregar_bala(bala1);
	mapa->agregar_bala(bala2);
	mapa->agregar_bala(bala3);
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
  Personaje::update(0, mapa);
  tiempo_pasado -= TIEMPO_ATAQUE;
}
