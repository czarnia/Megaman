#ifndef BALA_MAGNETMAN_H
#define BALA_MAGNETMAN_H

#include "bala_especial.h"

class Bala_magnetman: public Bala_especial{
	public:
		//Recibe una direccion en 'x', una
		//direccion en 'y' y una coordenada inicial y construye una bala.
		Bala_magnetman(int dir_x, int dir_y, Coordenada c, int id);
		//Destructor de la bala.
		virtual ~Bala_magnetman();
		//Hace que pasa el tiempo para la bala.
		virtual void update(float tiempo, Mapa* mapa);
		//Daña a un Personaje (caso por defecto).
		virtual void daniar(Personaje* pj);
		//Daña a un Megaman.
		virtual void daniar(Megaman* mega);
		//Daña a un Bombman.
		virtual void daniar(Bombman* b);
		//Daña a un Sparkman.
		virtual void daniar(Sparkman* s);
		//Daña a un Magnetman.
		virtual void daniar(Magnetman* m);
		//Daña a un Ringman.
		virtual void daniar(Ringman* r);
		//Daña a un Fireman.
		virtual void daniar(Fireman* f);
		//Daña a un Met.
		virtual void daniar(Met* met);
		//Daña a un Bumby.
		virtual void daniar(Bumby* b);
		//Daña a un Sniper.
		virtual void daniar(Snipper* s);
		//Daña a un Jumping_sniper.
		//virtual void daniar(Jumping_snipper* js);
		//Devuelve true si puede dañar a un Met cuando esta tras su escudo, false en
		//caso contrario.
		virtual bool dania_con_escudo(Met* m);
		//Devuelve true si puede dañar a un Snipper cuando esta tras su escudo, fal-
		//se en caso contrario.
		virtual bool dania_con_escudo(Snipper* s);
		//Devuelve true si puede dañar a un Jumping_snipper cuando esta tras su es-
		//cudo, false en caso contrario.
		virtual bool dania_con_escudo(Jumping_snipper* js);
};

#endif //BALA_MAGNETMAN_H
