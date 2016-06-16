#ifndef NUEVA_VIDA_H
#define NUEVA_VIDA_H

#include "premio.h"
#include "personaje.h"

class Nueva_vida: public Premio {
	public:
		//Dada una Coordenada, se crea una nueva_vida.
		Nueva_vida(Coordenada coord);
		//Dado un personaje, se interactura con el mismo.
		virtual void interactuar(Personaje *pj);
		//Devuelve la probabilidad de aparición de la nueva vida.
		static float get_probabilidad_aparicion();
};

#endif //NUEVA_VIDA_H
