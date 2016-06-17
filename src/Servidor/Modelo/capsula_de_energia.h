#ifndef CAPSULA_DE_ENERGIA_H
#define CAPSULA_DE_ENERGIA_H

#include "premio.h"
#include "personaje.h"
#include "personaje_pc.h"

class Capsula_de_energia: public Premio{
	public:
		//Dada una Coordenada, se crea una Capsula_de_energia.
		Capsula_de_energia(Coordenada coord, int tipo_capsula);
		//Dado un personaje, se interactura con el mismo.
		virtual void interactuar(Personaje *pj);
		//Dado un personaje, se interactura con el mismo.
		virtual void interactuar(Personaje_pc *pj);
		//Destructor de la capsula de energia.
		~Capsula_de_energia();
};

#endif //CAPSULA_DE_ENERGIA_H
