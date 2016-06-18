#include "snipper.h"
#include "arma_minion.h"

#define DERECHA -1
#define SNIPPER 5
#define TIEMPO_ESTADO 4

enum estado_npc_escudo{MURIENDO, ESCUDO_UP, ESCUDO_DOWN};

Snipper::Snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Personaje_npc_con_escudo(mapa, c, id),
arma(arma){
  estado_actual = ESCUDO_DOWN;
  tiempo_pasado = 0;
  tipo = SNIPPER;
}

bool Snipper::esta_bajo_escudo(){
  return (estado_actual == ESCUDO_UP);
}

bool Snipper::es_vulnerable(Bala* ataque){
  return ataque->dania_con_escudo(this);
}

void Snipper::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	if (tiempo_pasado >= TIEMPO_ESTADO){
		//paso el tiempo de estado:
		estado_actual = (estado_actual == ESCUDO_UP)? ESCUDO_DOWN : ESCUDO_UP;
		tiempo_pasado = 0;
		this->notificar_observadores();
	}
	if (estado_actual == ESCUDO_UP){
		return;
	}
	Bala *bala = arma->atacar(DERECHA, 0, coordenada.izquierda(ancho/2));
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
	Personaje::update(tiempo, mapa);
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

void Snipper::atacar(int dir, Mapa* mapa){}

void Snipper::mover(size_t tiempo, Mapa* mapa){}
