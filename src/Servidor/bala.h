#ifndef BALA_H
#define BALA_H

#include "actualizable.h"
#include "personaje.h"
#include "elemento.h"

class Bala: public Actualizable, public Elemento{
	public:
    //Destructor de la bala.
		virtual ~Bala();
    //Dado un personaje y un mapa, interactua con el personaje.
    virtual void interactuar(Personaje* pj);
    //Dado un personaje, dice si puede ubicarse en las mismas coordenadas que
    //este.
		virtual bool puede_ocupar(Personaje* pj);
    //Hace que pasa el tiempo para la bala.
    virtual void update(size_t tiempo) = 0;
		//Daña a un Personaje (caso por defecto).
		virtual void daniar(Personaje* pj) = 0;
		//Daña a un Megaman.
		virtual void daniar(Megaman* mega) = 0;
		//Daña a un Met.
		//virtual void dañar(Met* met) = 0;

};

#endif //BALA_H
