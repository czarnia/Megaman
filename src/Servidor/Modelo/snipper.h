#ifndef SNIPPER_H
#define SNIPPER_H

#include "personaje.h"

class Arma_minion;

class Snipper : public Personaje {
	protected:
		Arma_minion* arma;
		bool tras_escudo;
	public:
		Snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		//Hace que el personaje ataque.
		void atacar(int dir, Mapa* mapa);		//NO TIENE SENTIDO PARA NPCs!
		//Le hace un update al personaje.
		virtual void update(size_t tiempo, Mapa* mapa);
		//Dada una bala, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Hace que el personaje se mueva;
		void mover(size_t tiempo, Mapa* mapa);  //NO TIENE SENTIDO PARA NPCs!
		//Dada una direccion representada como un int, saca un movimiento en dicha
		//direccion.
		void sacar_movimiento(int direccion);	//NO TIENE SENTIDO PARA NPCs!
		//Dada una direccion representada como un int, agrega un movimiento en dicha
		//direccion.
		void agregar_movimiento(int direccion);	//NO TIENE SENTIDO PARA NPCs!	
};

#endif //SNIPPER_H
