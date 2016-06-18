#include "met.h"
#include "bala.h"
#include "arma_minion.h"

#define TIEMPO_ATAQUE 2
#define TIPO_MET 4

enum estado_npc_escudo{MURIENDO, ESCUDO_UP = 7, ESCUDO_DOWN};

Met::Met(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Personaje_npc_con_escudo(mapa, c, id),
arma(arma){
  estado_actual = ESCUDO_DOWN;
  tiempo_pasado = 0;
  tipo = TIPO_MET;
}

void Met::atacar(int dir, Mapa* mapa){
	if (estado_actual == ESCUDO_UP){
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
	if ((estado_actual == ESCUDO_UP) && !(es_vulnerable(ataque))){
		return;
	}
	ataque->daniar(this);
	if(!this->esta_vivo()){
		estado_actual = MURIENDO;
	}
}

void Met::update(size_t tiempo){
  tiempo_pasado += tiempo;
  if (tiempo_pasado < TIEMPO_ATAQUE){
    return;
  }
  estado_actual = (estado_actual == ESCUDO_UP)? ESCUDO_DOWN : ESCUDO_UP;
  Personaje::update(0, mapa);
  Personaje::notificar_observadores();
  tiempo_pasado -= TIEMPO_ATAQUE;
  Personaje::update(tiempo, mapa);
}

bool Met::esta_bajo_escudo(){
	return (estado_actual == ESCUDO_UP);
}

bool Met::es_vulnerable(Bala* ataque){
  return ataque->dania_con_escudo(this);
}
