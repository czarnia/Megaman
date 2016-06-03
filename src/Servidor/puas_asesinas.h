#ifndef PUAS_ASESINAS_H
#define PUAS_ASESINAS_H

#include "elemento.h"

class Personaje;

class Puas_asesinas: public Elemento{
	public:
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Personaje* pj);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Destructor de las Puas_asesinas.
		~Puas_asesinas();
};

#endif //PUAS_ASESINAS_H
