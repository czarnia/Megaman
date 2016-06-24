#include "met.h"
#include "bala.h"
#include "arma_minion.h"

#define TIEMPO_ATAQUE 40
#define TIPO_MET 4

#define ALTO 30
#define ANCHO 30

enum estados {MURIENDO, DISPARANDO, RESPAWNEANDO, CORRIENDO, SALTANDO,
		IDLE, ESCALANDO, USA_ESCUDO,  NO_USA_ESCUDO};

Met::Met(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Personaje_npc_con_escudo(mapa, c, id),
arma(arma){
  estado_actual = NO_USA_ESCUDO;
  tiempo_pasado = 0;
  tipo = TIPO_MET;
	alto = ALTO;
	ancho = ANCHO;
}

void Met::atacar(int dir, Mapa* mapa){
	if (estado_actual == USA_ESCUDO){
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

void Met::mover(float tiempo, Mapa* mapa){
	//mapa->interactuar_con_entorno(this);
}

void Met::recibir_ataque(Bala* ataque){
	if ((estado_actual == USA_ESCUDO) && !(es_vulnerable(ataque))){
		return;
	}
	ataque->daniar(this);
	if(!this->esta_vivo()){
		estado_actual = MURIENDO;
	}
	notificar_observadores();
}

void Met::update(float tiempo, Mapa *mapa){
  if (activo){
    tiempo_pasado += tiempo;
  }
  if (tiempo_pasado < TIEMPO_ATAQUE || !activo){
    return;
  }
  estado_actual = (estado_actual == USA_ESCUDO)? NO_USA_ESCUDO : USA_ESCUDO;
  tiempo_pasado -= TIEMPO_ATAQUE;
  atacar(0, mapa);
}

bool Met::esta_bajo_escudo(){
	return (estado_actual == USA_ESCUDO);
}

bool Met::es_vulnerable(Bala* ataque){
  return ataque->dania_con_escudo(this);
}
