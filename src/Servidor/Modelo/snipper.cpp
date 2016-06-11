#include "snipper.h"
#define DERECHA -1

Snipper::Snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id): 
Personaje(mapa, c, id),
arma(arma){
  tras_escudo = false;
  tiempo_pasado = 0;
}

void Snipper::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	if (tras_escudo){
		return;
	}
	Bala *bala = arma->atacar(DERECHA, 0, pos_inicial);
	mapa->agregar_bala(bala1);
	bala->notificar_observadores();
}

void Snipper::recibir_ataque(Bala* ataque){}

