#ifndef MEGAMAN_H
#define MEGAMAN_H

#include "mapa.h"

class Arma;
class Arma_megaman;

class Megaman: public Personaje{
	private:
		Mapa *mapa;
		std::vector<Arma*> armas;
		size_t arma_act;
	public:
		Megaman(Mapa *mapa, Coordenada c, Arma_megaman *arma, int id);
		virtual void atacar(int dir, Mapa* mapa);
		virtual void mover(size_t tiempo, Mapa* mapa);
		virtual void recibir_ataque(Bala* ataque);
		virtual void update(size_t tiempo);
		virtual void agregar_arma(Arma *arma);
};

#endif //MEGAMAN_H
