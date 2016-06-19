#include "ringman.h"
#include "bala.h"
#include "arma_ringman.h"

#define TIEMPO_ATAQUE 2
#define TIPO_RINGMAN 23

#define DERECHA 3
#define IZQUIERDA 4

Ringman::Ringman(Mapa *mapa, Coordenada c, Arma_ringman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_RINGMAN;
}

void Ringman::atacar(int dir, Mapa* mapa){
  Bala* bala;
  if (dir == DERECHA){
    bala = arma->atacar(1, 3, coordenada.derecha(ancho/2).arriba(alto/2));
  }if (dir == IZQUIERDA){
    bala = arma->atacar(-1, 3, coordenada.izquierda(ancho/2).arriba(alto/2));
  }
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
}

void Ringman::mover(float tiempo, Mapa* mapa){ }

void Ringman::recibir_ataque(Bala* ataque){}

void Ringman::update(float tiempo){}
