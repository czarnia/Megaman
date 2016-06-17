#include "bombman.h"
#include "bala.h"
#include "arma_bombman.h"

#define TIEMPO_ATAQUE 2
#define TIPO_BOMBMAN 30

#define DERECHA 3
#define IZQUIERDA 4

Bombman::Bombman(Mapa *mapa, Coordenada c, Arma_bombman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tras_escudo = false;
  tiempo_pasado = 0;
  tipo = TIPO_BOMBMAN;
}

void Bombman::atacar(int dir, Mapa* mapa){
  Bala* bala;
  if (dir == DERECHA){
    bala = arma->atacar(1, 3, coordenada.derecha(ancho/2).arriba(alto/2));
  }if (dir == IZQUIERDA){
    bala = arma->atacar(-1, 3, coordenada.izquierda(ancho/2).arriba(alto/2));
  }
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
}

void Bombman::mover(size_t tiempo, Mapa* mapa){ }

void Bombman::recibir_ataque(Bala* ataque){
  ataque->daniar(this);
}

void Bombman::update(size_t tiempo){
  tiempo_pasado += tiempo;
  if (tiempo_pasado < TIEMPO_ATAQUE){
    return;
  }
  Personaje::update(0, mapa);
  tiempo_pasado -= TIEMPO_ATAQUE;
}

