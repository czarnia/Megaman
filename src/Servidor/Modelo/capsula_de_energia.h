#ifndef CAPSULA_DE_ENERGIA_H
#define CAPSULA_DE_ENERGIA_H

#include "premio.h"
#include "personaje.h"

class Capsula_de_energia: public Premio{
	public:
		//Dada una Coordenada, se crea una Capsula_de_energia.
		Capsula_de_energia(Coordenada coord);
		//Dado un personaje, se interactura con el mismo.
		virtual void interactuar(Personaje *pj);
		//Devuelve la probabilidad de aparición de la capsula de energia.
		static float get_probabilidad_aparicion();
		//Destructor de la capsula de energia.
		~Capsula_de_energia();
};

#endif //CAPSULA_DE_ENERGIA_H
