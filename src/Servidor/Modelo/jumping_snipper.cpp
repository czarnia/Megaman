#include "jumping_snipper.h"
#define TIEMPO_ESTADO 4

JumpingSnipper::JumpingSnipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id): 
Personaje(mapa, c, id),
arma(arma){
  tras_escudo = false;
  flotando = false;
  tiempo_pasado = 0;
}

void JumpingSnipper::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	if (tiempo_pasado >= TIEMPO_ESTADO){
		//paso el tiempo de estado:
		tras_escudo = !tras_escudo;
		tiempo_pasado = 0;
		this->notificar_observadores();
	}
	if (tras_escudo || flotando){
		return;
	}
	//Dispara:
	Bala *bala = arma->atacar(DERECHA, 0, pos_inicial);
	mapa->agregar_bala(bala1);
	bala->notificar_observadores();
	//Salta:
	salto_snipper->mover(mapa, this);
}
