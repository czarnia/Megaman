#include "bombman.h"
#include "bala.h"
#include "arma_bombman.h"
#include <cstdlib>

#define TIEMPO_ATAQUE 2
#define TIPO_BOMBMAN 20
#define RAND_RANGE 2
#define ARRIBA 1
#define DERECHA 3
#define IZQUIERDA 4

Bombman::Bombman(Mapa *mapa, Coordenada c, Arma_bombman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_BOMBMAN;
}

void Bombman::atacar(int dir, Mapa* mapa){
	Bala* bala;
	//Coordenada default:
	Coordenada coord_ataque = coordenada.derecha(ancho/2).arriba(alto/2);
	if (dir == DERECHA){
		bala = arma->atacar(DERECHA, ARRIBA, coordenada.derecha(ancho/2).arriba(alto/2));
	}if (dir == IZQUIERDA){
		bala = arma->atacar(IZQUIERDA, ARRIBA, coordenada.izquierda(ancho/2).arriba(alto/2));
	}
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
}

void Bombman::mover(float tiempo, Mapa* mapa){ 
	movimiento.mover(mapa, this, tiempo);
}

void Bombman::recibir_ataque(Bala* ataque){
	ataque->daniar(this);
}

void Bombman::update(float tiempo){
	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_ATAQUE){
		return;
	}
	Personaje::update(tiempo, mapa);
	tiempo_pasado -= TIEMPO_ATAQUE;
	int dir_ataque = rand() %RAND_RANGE + DERECHA;
	atacar(dir_ataque, mapa);
}
