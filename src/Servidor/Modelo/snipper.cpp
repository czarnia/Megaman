#include "snipper.h"
#include "arma_minion.h"

#define IZQUIERDA -1
#define SNIPPER 5
#define TIEMPO_ESTADO 100

#define ALTO 60
#define ANCHO 30

enum estados {MURIENDO, DISPARANDO, RESPAWNEANDO, CORRIENDO, SALTANDO,
		IDLE, ESCALANDO, ESCUDO_UP, ESCUDO_DOWN};

Snipper::Snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Personaje_npc_con_escudo(mapa, c, id),
arma(arma){
  estado_actual = ESCUDO_DOWN;
  tiempo_pasado = 0;
  tipo = SNIPPER;
	alto = ALTO;
	ancho = ANCHO;
}

bool Snipper::esta_bajo_escudo(){
  return (estado_actual == ESCUDO_UP);
}

bool Snipper::es_vulnerable(Bala* ataque){
  return ataque->dania_con_escudo(this);
}

void Snipper::update(float tiempo, Mapa* mapa){
  if (activo){
    tiempo_pasado += tiempo;
  }
  if ((tiempo_pasado < TIEMPO_ESTADO) || !activo){
    estado_actual = IDLE;
    return;
	}
	//paso el tiempo de estado:
	estado_actual = (estado_actual == ESCUDO_UP)? ESCUDO_DOWN : ESCUDO_UP;
	tiempo_pasado -= TIEMPO_ESTADO;
	this->notificar_observadores();
	if (estado_actual != ESCUDO_UP){
    atacar(IZQUIERDA, mapa);
	}
  mover(tiempo, mapa);
	//Personaje::update(tiempo, mapa);
}

void Snipper::recibir_ataque(Bala* ataque){
	if ((estado_actual == ESCUDO_UP) && !(es_vulnerable(ataque))){
		return;
	}
	ataque->daniar(this);
	if(!this->esta_vivo()){
		estado_actual = MURIENDO;
	}
}

void Snipper::atacar(int dir, Mapa* mapa){
  estado_actual = DISPARANDO;
  Bala *bala = arma->atacar(IZQUIERDA, 0, coordenada.izquierda(ancho/2));
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
}

void Snipper::mover(float tiempo, Mapa* mapa){
  movimiento.mover(mapa, this, tiempo);
}
