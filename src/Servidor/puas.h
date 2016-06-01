#ifndef PUAS_H
#define PUAS_H

#include "elemento.h"

class Personaje;

class Puas: public Elemento{
	public:
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Personaje* pj);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Destructor de las Puas.
		~Puas();
};

#endif //PUAS_H
