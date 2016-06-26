#include "bombman.h"
#include "bala.h"
#include "arma_bombman.h"
#include <cstdlib>

#define TIEMPO_ATAQUE 1000
#define TIPO_BOMBMAN 20
#define RAND_RANGE 2
#define ARRIBA 1
#define DERECHA 1
#define IZQUIERDA -1
#define ALTO 60
#define ANCHO 30

Bombman::Bombman(Mapa *mapa, Coordenada c, Arma_bombman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_BOMBMAN;
  alto = ALTO;
  ancho = ANCHO;
}

void Bombman::atacar(int dir, Mapa* mapa){
	Bala* bala;
	if (dir > 0){
		bala = arma->atacar(DERECHA, ARRIBA, coordenada.derecha(ancho/2).arriba(alto/2));
		mapa->agregar_bala(bala);
		bala->notificar_observadores();
	}if (dir < 0){
		bala = arma->atacar(IZQUIERDA, ARRIBA, coordenada.izquierda(ancho/2).arriba(alto/2));
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
	mover(tiempo, mapa);
	if (tiempo_pasado < TIEMPO_ATAQUE|| !activo){
		return;
	}
	tiempo_pasado = 0;
	Coordenada c_enemigo = mapa->obtener_coordenada_enemigo(this);
	int delta_x = c_enemigo.obtener_abscisa()-coordenada.obtener_abscisa();
	atacar(delta_x, mapa);
}
