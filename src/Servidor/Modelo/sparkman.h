#ifndef SPARKMAN_H
#define SPARKMAN_H

#include "personaje.h"
#include <vector>

class Arma_sparkman;

class Sparkman: public Personaje{
	private:
		Mapa *mapa;
		size_t tiempo_pasado;
		Arma_sparkman* arma;
	public:
		Sparkman(Mapa *mapa, Coordenada c, Arma_sparkman* arma, int id);
		virtual void atacar(int dir, Mapa* mapa);
		virtual void mover(size_t tiempo, Mapa* mapa);
		virtual void recibir_ataque(Bala* ataque);
		virtual void update(size_t tiempo);
		virtual void sacar_movimiento(int direccion);
		virtual void agregar_movimiento(int direccion);
  private:
    std::vector<Bala*> balas_ataque();
};

#endif //SPARKMAN_H
