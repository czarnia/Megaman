#ifndef BALA_NORMAL_H
#define BALA_NORMAL_H

#include "bala.h"

class Bala_normal : public Bala {
	public:
    //Destructor de la bala.
		virtual ~Bala_normal();
    //Hace que pasa el tiempo para la bala.
    virtual void update(size_t tiempo, Mapa* mapa);
		//Daña a un Personaje (caso por defecto).
		virtual void daniar(Personaje* pj);
		//Daña a un Megaman.
		virtual void daniar(Megaman* mega);
		//Daña a un Met.
		virtual void daniar(Met* met);

};

#endif //BALA_NORMAL_H
