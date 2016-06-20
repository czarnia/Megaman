#ifndef RINGMAN_H
#define RINGMAN_H

#include "personaje_npc.h"

class Arma_ringman;

class Ringman: public Personaje_npc{
	private:
		Mapa *mapa;
		float tiempo_pasado;
		Arma_ringman* arma;
		//StrategyMoverRingman movimiento;
	public:
		//Dado un Mapa*, una coordenada, un Arma_ringman* y un id, crea un ringman.
		Ringman(Mapa *mapa, Coordenada c, Arma_ringman* arma, int id);
		//Dado una Mapa* y una direccion, ataca.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo pasado y un Mapa*, se mueve.
		virtual void mover(float tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(float tiempo);
};

#endif //RINGMAN_H

