#include "jumping_snipper.h"
#include "arma_minion.h"
#define TIEMPO_ESTADO 4
#define DERECHA -1

Jumping_snipper::Jumping_snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Snipper(mapa, c, arma, id){
  tras_escudo = false;
  flotando = false;
  tiempo_pasado = 0;
}

void Jumping_snipper::update(size_t tiempo, Mapa* mapa){
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
	Bala *bala = arma->atacar(DERECHA, 0, coordenada.izquierda(ancho/2));
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
	//Salta:
	salto_snipper.mover(mapa, this, tiempo_pasado);
}
