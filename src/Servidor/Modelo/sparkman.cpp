#include "sparkman.h"
#include "bala.h"
#include "arma_sparkman.h"

#define TIEMPO_ACCION 2
#define TIPO_SPARKMAN 22

Sparkman::Sparkman(Mapa *mapa, Coordenada c, Arma_sparkman* arma, int id):
Personaje_npc(mapa, c, id),
arma(arma){
  tiempo_pasado = 0;
  tipo = TIPO_SPARKMAN;
}

void Sparkman::atacar(int dir, Mapa* mapa){
	std::vector<Bala*> balas = balas_ataque();
  for (size_t i = 0; i < balas.size(); i++){
    mapa->agregar_bala(balas[i]);
    balas[i]->notificar_observadores();
  }
}

void Sparkman::mover(float tiempo, Mapa* mapa){
	movimiento.mover(mapa, this, tiempo);
}

void Sparkman::recibir_ataque(Bala* ataque){
  ataque->daniar(this);
}

void Sparkman::update(float tiempo){
  tiempo_pasado += tiempo;
  mover(tiempo, mapa);
  if (tiempo_pasado < TIEMPO_ACCION){
    return;
  }
  //atacar
}

std::vector<Bala*> Sparkman::balas_ataque(){ //Ataca en un círculo medio defo.
  std::vector<Bala*> balas;

  Coordenada pos_inicial = coordenada.izquierda(ancho/2);
  balas.push_back(arma->atacar(-1, 0, pos_inicial));
  balas.push_back(arma->atacar(-1, 1, pos_inicial));
  balas.push_back(arma->atacar(-1, -1, pos_inicial));

  pos_inicial = coordenada.derecha(ancho/2);
  balas.push_back(arma->atacar(1, 0, pos_inicial));
  balas.push_back(arma->atacar(1, 1, pos_inicial));
  balas.push_back(arma->atacar(1, -1, pos_inicial));

  balas.push_back(arma->atacar(0 , 1, coordenada.abajo(alto/2)));
  balas.push_back(arma->atacar(0 , -1, coordenada.arriba(alto/2)));

  return balas;
}
