#ifndef BALA_FIREMAN_H
#define BALA_FIREMAN_H

#include "bala.h"

class Bala_fireman: public Bala{
	public:
		//Recibe una direccion en 'x', una
		//direccion en 'y' y una coordenada inicial y construye una bala.
		Bala_fireman(int dir_x, int dir_y, Coordenada c, int id);
		//Destructor de la bala.
		virtual ~Bala_fireman();
		//Hace que pasa el tiempo para la bala.
		virtual void update(size_t tiempo, Mapa* mapa);
		//Daña a un Personaje (caso por defecto).
		virtual void daniar(Personaje* pj);
		//Daña a un Megaman.
		virtual void daniar(Megaman* mega);
		//Daña a un Met.
		virtual void daniar(Met* met);
		//Daña a un Bumby.
		virtual void daniar(Bumby* b);
		//Daña a un Sniper.
		virtual void daniar(Snipper* s);
		//Daña a un Jumping_sniper.
		virtual void daniar(Jumping_snipper* js);
};

#endif //BALA_FIREMAN_H
