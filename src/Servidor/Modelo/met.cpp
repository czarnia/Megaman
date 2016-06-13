#include "met.h"
#include "bala.h"
#include "arma_minion.h"

#define TIEMPO_ATAQUE 2
#define TIPO_MET 4

Met::Met(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Personaje(mapa, c, id),
arma(arma){
  tras_escudo = false;
  tiempo_pasado = 0;
  tipo = TIPO_MET;
}

void Met::atacar(int dir, Mapa* mapa){
	if (tras_escudo){
		return;
	}
	Bala *bala1, *bala2, *bala3;
	Coordenada pos_inicial = coordenada.izquierda(ancho/2);
	bala1 = arma->atacar(-1, 0, pos_inicial);
	bala2 = arma->atacar(-1, 1, pos_inicial);
	bala3 = arma->atacar(-1, -1, pos_inicial);
	mapa->agregar_bala(bala1);
	mapa->agregar_bala(bala2);
	mapa->agregar_bala(bala3);
	bala1->notificar_observadores();
	bala2->notificar_observadores();
	bala3->notificar_observadores();
}

void Met::mover(size_t tiempo, Mapa* mapa){ } //el met no se mueve.

void Met::recibir_ataque(Bala* ataque){
  if (tras_escudo && !(es_vulnerable(ataque))){
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

void Met::sacar_movimiento(int direccion){}

void Met::agregar_movimiento(int direccion){}

bool Met::es_vulnerable(Bala* ataque){
  return ataque->dania_con_escudo(this);
}
