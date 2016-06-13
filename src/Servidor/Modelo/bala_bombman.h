#ifndef BALA_BOMBMAN_H
#define BALA_BOMBMAN_H

#include "bala.h"
#include "personaje.h"
#include "megaman.h"
#include "met.h"

class Bala_bombman: public Bala {
	public:
		//Recibe una direccion en 'x', una
		//direccion en 'y' y una coordenada inicial y construye una bala.
		Bala_bombman(int dir_x, int dir_y, Coordenada c, int id);
		//Destructor de la bala.
		virtual ~Bala_bombman();
		//Hace que pasa el tiempo para la bala.
		virtual void update(size_t tiempo, Mapa* mapa);
		//Daña a un Personaje (caso por defecto).
		virtual void daniar(Personaje* pj);
		//Daña a un Megaman.
		virtual void daniar(Megaman* mega);
		//Daña a un Met.
		virtual void daniar(Met* met);
};

#endif //BALA_BOMBMAN_H
