#include "fireman.h"
#include "bala.h"
#include "arma_fireman.h"

#define TIEMPO_ACCION 2
#define TIPO_FIREMAN -1 //TODO: definir el id.

#define DERECHA 3
#define IZQUIERDA 4

Fireman::Fireman(Mapa *mapa, Coordenada c, Arma_fireman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_FIREMAN;
  atacando = false;
}

void Fireman::atacar(int dir, Mapa* mapa){
  if (!atacando){
    return;
  }
  Bala* bala;
  if (dir == DERECHA){
    bala = arma->atacar(1, 0, coordenada.derecha(ancho/2));
  }if (dir == IZQUIERDA){
    bala = arma->atacar(-1, 0, coordenada.izquierda(ancho/2));
  }
	mapa->agregar_bala(bala);
  bala->notificar_observadores();
}

void Fireman::mover(size_t tiempo, Mapa* mapa){ } //TODO: hacer el mover.

void Fireman::recibir_ataque(Bala* ataque){
  ataque->daniar(this);
}

void Fireman::update(size_t tiempo){
  tiempo_pasado += tiempo;
  if (tiempo_pasado < TIEMPO_ACCION){
    return;
  }
  atacando = !atacando;
  tiempo_pasado -= TIEMPO_ACCION;
  //if (tiempo_pasado%0.25){ //lanza una llamarada continua, es decir, son
  //  atacar();              //varias balas seguidas.
  //}
  //mover
}
