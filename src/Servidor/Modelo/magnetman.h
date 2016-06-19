#ifndef MAGNETMAN_H
#define MAGNETMAN_H

#include "personaje_npc.h"
#include <vector>

class Arma_magnetman;

class Magnetman: public Personaje_npc{
	private:
		Mapa *mapa;
		float tiempo_pasado;
		Arma_magnetman* arma;
    bool atacando;
	public:
		//Dado un Mapa*, una coordenada, un Arma_magnetman* 
		//y un id, crea un magnetan.
		Magnetman(Mapa *mapa, Coordenada c, Arma_magnetman* arma, int id);
		//Dado una Mapa* y una direccion, ataca.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo pasado y un Mapa*, se mueve.
		virtual void mover(float tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(float tiempo);
};

#endif //MAGNETMAN_H

