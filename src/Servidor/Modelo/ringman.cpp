#include "ringman.h"
#include "bala.h"
#include "arma_ringman.h"

#define TIEMPO_ATAQUE 2
#define TIPO_RINGMAN 23

#define DERECHA 3
#define IZQUIERDA 4

#define ALTO 60
#define ANCHO 30

Ringman::Ringman(Mapa *mapa, Coordenada c, Arma_ringman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_RINGMAN;
  alto = ALTO;
  ancho = ANCHO;
}

void Ringman::atacar(int dir, Mapa* mapa){
	/*Bala* bala;
  	int delta_x = c_enemigo.obtener_abscisa()-(pj->coordenada.obtener_abscisa());
	int dir = delta_x < 0? IZQUIERDA : DERECHA;
	if (dir == DERECHA){
		bala = arma->atacar(1, 3, coordenada.derecha(ancho/2).arriba(alto/2));
	}if (dir == IZQUIERDA){
		bala = arma->atacar(-1, 3, coordenada.izquierda(ancho/2).arriba(alto/2));
	}
	mapa->agregar_bala(bala);
	bala->notificar_observadores();*/
}

void Ringman::mover(float tiempo, Mapa* mapa){
	movimiento.mover(mapa, this, tiempo);
}

void Ringman::recibir_ataque(Bala* ataque){
	ataque->daniar(this);
}

void Ringman::update(float tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	mover(tiempo, mapa);
	if (tiempo_pasado < TIEMPO_ATAQUE){
		return;
	}
	//atacando = !atacando;
	//tiempo_pasado -= TIEMPO_ATAQUE;
	//atacar(0, mapa);
}
