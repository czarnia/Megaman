#include "snipper.h"
#include "arma_minion.h"
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
	Bala *bala = arma->atacar(DERECHA, 0, coordenada.izquierda(ancho/2));
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
}

void Snipper::recibir_ataque(Bala* ataque){}


void Snipper::atacar(int dir, Mapa* mapa){}

void Snipper::mover(size_t tiempo, Mapa* mapa){}

void Snipper::sacar_movimiento(int direccion){}

void Snipper::agregar_movimiento(int direccion){}	

