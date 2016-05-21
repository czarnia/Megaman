#include "personaje.h"

class Elemento{
	public:
		virtual void interactuar(Personaje *pj);
		virtual bool puede_ocupar(Personaje *pj);
}
