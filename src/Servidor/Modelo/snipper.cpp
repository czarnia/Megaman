#include "snipper.h"
#include "arma_minion.h"

#define DERECHA -1
#define SNIPPER 5

Snipper::Snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id):
Personaje_npc_con_escudo(mapa, c, id),
arma(arma){
  tras_escudo = false;
  tiempo_pasado = 0;
  tipo = SNIPPER;
}

bool Snipper::esta_bajo_escudo(){
  return tras_escudo;
}

bool Snipper::es_vulnerable(Bala* ataque){
  return ataque->dania_con_escudo(this);
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

void Snipper::recibir_ataque(Bala* ataque){
  if (tras_escudo && !(es_vulnerable(ataque))){
    return;
  }
  ataque->daniar(this);
}

void Snipper::atacar(int dir, Mapa* mapa){}

void Snipper::mover(size_t tiempo, Mapa* mapa){}
