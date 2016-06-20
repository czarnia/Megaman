#include "fireman.h"
#include "bala.h"
#include "arma_fireman.h"

#define TIEMPO_ACCION 2
#define TIPO_FIREMAN 24

#define DERECHA 3
#define IZQUIERDA 4

Fireman::Fireman(Mapa *mapa, Coordenada c, Arma_fireman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_FIREMAN;
  atacando = false;
}

void Fireman::atacar(int dir_x, Mapa* mapa){
	if (!atacando){
		return;
	}
	Bala *bala1, *bala2, *bala3;
	if (dir == DERECHA){
		bala1 = arma->atacar(dir_x, 0, coordenada.derecha(ancho/2).arriba(alto/2));
		bala2 = arma->atacar(dir_x, 0, coordenada.derecha(ancho/2));
		bala3 = arma->atacar(dir_x, 0, coordenada.derecha(ancho/2).abajo(alto/2));
	}
	if (dir == IZQUIERDA){
		bala1 = arma->atacar(dir_x, 0, coordenada.izquierda(ancho/2).arriba(alto/2));
		bala2 = arma->atacar(dir_x, 0, coordenada.izquierda(ancho/2));
		bala3 = arma->atacar(dir_x, 0, coordenada.izquierda(ancho/2).abajo(alto/2));
	}
	mapa->agregar_bala(bala1);
	mapa->agregar_bala(bala2);
	mapa->agregar_bala(bala3);
	bala1->notificar_observadores();
	bala2->notificar_observadores();
	bala3->notificar_observadores();
}

void Fireman::mover(float tiempo, Mapa* mapa){ } 

void Fireman::recibir_ataque(Bala* ataque){
  ataque->daniar(this);
}

void Fireman::update(float tiempo){
	tiempo_pasado += tiempo;
	if (tiempo_pasado < TIEMPO_ACCION){
		return;
	}
	atacando = !atacando;
	tiempo_pasado -= TIEMPO_ACCION;
	int delta_x = c_enemigo.obtener_abscisa()-(pj->coordenada.obtener_abscisa());
	int dir = delta_x < 0? IZQUIERDA : DERECHA;
	atacar(dir, mapa);
}
