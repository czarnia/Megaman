#ifndef NUEVA_VIDA_H
#define NUEVA_VIDA_H

#include "premio.h"
#include "personaje.h"

class Nueva_vida: public Premio {
	public:
		Nueva_vida(Coordenada coord);
		virtual void interactuar(Personaje *pj);
		static float get_probabilidad_aparicion();
};

#endif //NUEVA_VIDA_H
