#ifndef CAPSULA_DE_PLASMA_H
#define CAPSULA_DE_PLASMA_H

#include "premio.h"
#include "personaje.h"

class Capsula_de_plasma: public Premio{
	public:
		//Dada una Coordenada, se crea una Capsula_de_plasma.
		Capsula_de_plasma(Coordenada coord, int tipo_capsula);
		//Dado un personaje, se interactura con el mismo.
		virtual void interactuar(Personaje *pj);
		//Destructor de la capsula de plasma.
		~Capsula_de_plasma();
};

#endif //CAPSULA_DE_PLASMA_H
