#include "bumby.h"
#include "arma_minion.h"
#include <cstdlib>

#define TIEMPO_MOVER 2
#define TIEMPO_ATACAR 3
#define CANT_DIRECCIONES 3
#define AVANZAR_X 1
#define RETROCEDER_X -1
#define BAJAR_Y 1
#define BUMBY 2

enum direcciones_ataque{DERECHA_ABAJO, CENTRO_ABAJO, IZQUIERDA_ABAJO};
enum estado_npc{MURIENDO};

Bumby::Bumby(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = BUMBY;
  mover_bumby = new StrategyMoverBumby();
}

void Bumby::atacar(int dir, Mapa* mapa){
	Coordenada pos_inicial(-1, -1);
	int dir_x = 0;
	int dir_y = BAJAR_Y;
	switch(dir){
		case DERECHA_ABAJO:
			pos_inicial = coordenada.derecha(ancho/2).abajo(alto/2);
			dir_x = RETROCEDER_X;
			break;
		case CENTRO_ABAJO:
			pos_inicial = coordenada.abajo(alto/2);
			dir_x = AVANZAR_X;
			break;
		case IZQUIERDA_ABAJO:
			pos_inicial = coordenada.izquierda(ancho/2).abajo(alto/2);
			break;
	}
	Bala *bala = arma->atacar(dir_x, dir_y, pos_inicial);
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
}

void Bumby::update(float tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
  if (tiempo_pasado < TIEMPO_MOVER){
    return;
  }
	if (tiempo_pasado >= TIEMPO_MOVER){
    mover(tiempo, mapa);
	}
	/*if (tiempo_pasado >= TIEMPO_ATACAR){
		tiempo_pasado = 0;
		int dir = std::rand() % CANT_DIRECCIONES;
		atacar(dir, mapa);
	}*/
  tiempo_pasado -= TIEMPO_MOVER;
	//Personaje::update(tiempo, mapa);
}

void Bumby::recibir_ataque(Bala* ataque){
	//TODO: A implementar!
	if(!this->esta_vivo()){
		estado_actual = MURIENDO;
	}
}

void Bumby::mover(float tiempo, Mapa* mapa){
  mover_bumby->mover(mapa, this, tiempo);
  this->notificar_observadores();
}
