#ifndef CAPSULA_DE_ENERGIA_H
#define CAPSULA_DE_ENERGIA_H

#include "premio.h"
#include "personaje.h"

class Capsula_de_energia: public Premio{
	public:
		Capsula_de_energia(Coordenada coord);
		virtual void interactuar(Personaje *pj);
		static float get_probabilidad_aparicion();
		~Capsula_de_energia();
};

#endif //CAPSULA_DE_ENERGIA_H
