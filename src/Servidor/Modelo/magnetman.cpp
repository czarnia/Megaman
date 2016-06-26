#include "magnetman.h"
#include "bala.h"
#include "arma_magnetman.h"

#define TIEMPO_ATAQUE 200
#define TIPO_MAGNETMAN 21

#define DERECHA 3
#define IZQUIERDA 4

#define ALTO 60
#define ANCHO 30

Magnetman::Magnetman(Mapa *mapa, Coordenada c,
Arma_magnetman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
	tiempo_pasado = 0;
	tipo = TIPO_MAGNETMAN;
	alto = ALTO;
	ancho = ANCHO;
}

void Magnetman::atacar(int dir, Mapa* mapa){
	Bala* bala;
	if (dir == DERECHA){
		bala = arma->atacar(1, 3, coordenada.derecha(ancho/2).arriba(alto/2));
		mapa->agregar_bala(bala);
		bala->notificar_observadores();
	}if (dir == IZQUIERDA){
		bala = arma->atacar(-1, 3, coordenada.izquierda(ancho/2).arriba(alto/2));
		mapa->agregar_bala(bala);
		bala->notificar_observadores();
	}
}

void Magnetman::mover(float tiempo, Mapa* mapa){
	movimiento.mover(mapa, this, tiempo);
}

void Magnetman::recibir_ataque(Bala* ataque){}

void Magnetman::update(float tiempo, Mapa *mapa){
	tiempo_pasado += tiempo;
	mover(tiempo, mapa);
	if (tiempo_pasado < TIEMPO_ATAQUE|| !activo){
		return;
	}
	tiempo_pasado = 0;
	//Coordenada c_enemigo = mapa->obtener_coordenada_enemigo(this);
	//int delta_x = c_enemigo.obtener_abscisa()-coordenada.obtener_abscisa();
	//atacar(delta_x, mapa);
}
