#include "bombman.h"
#include "bala.h"
#include "arma_bombman.h"
#include <cstdlib>

#define TIEMPO_ATAQUE 2
#define TIPO_BOMBMAN 20
#define RAND_RANGE 2
#define ARRIBA 1
#define DERECHA 1
#define IZQUIERDA -1

Bombman::Bombman(Mapa *mapa, Coordenada c, Arma_bombman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_BOMBMAN;
}

void Bombman::atacar(int dir, Mapa* mapa){
	Bala* bala;
	if (dir > 0){
		bala = arma->atacar(DERECHA, ARRIBA, coordenada.derecha(ancho/2).arriba(alto/2));
	}if (dir < 0){
		bala = arma->atacar(IZQUIERDA, ARRIBA, coordenada.izquierda(ancho/2).arriba(alto/2));
	}
	if (bala != NULL){
		mapa->agregar_bala(bala);
		bala->notificar_observadores();
	}
}

void Bombman::mover(float tiempo, Mapa* mapa){ 
	movimiento.mover(mapa, this, tiempo);
}

void Bombman::recibir_ataque(Bala* ataque){
	ataque->daniar(this);
}

void Bombman::update(float tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_ATAQUE || !activo){
		return;
	}
	mover(tiempo, mapa);
	tiempo_pasado -= TIEMPO_ATAQUE;
	Coordenada c_enemigo = mapa->obtener_coordenada_enemigo(this);
	int delta_x = c_enemigo.obtener_abscisa()-coordenada.obtener_abscisa();
	atacar(delta_x, mapa);
}
