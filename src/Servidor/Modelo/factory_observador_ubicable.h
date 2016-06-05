#ifndef FACTORY_OBSERVADOR_UBICABLE_H
#define FACTORY_OBSERVADOR_UBICABLE_H

class Juego;
#include "ubicable.h"
#include "observador_ubicable.h"

class Factory_observador_ubicable {
	private:
		Juego *juego;
		std::vector<Observador*> creados;
	public:
		Factory_observador_ubicable(Juego *j);
		void crear(Ubicable *obs);
		~Factory_observador_ubicable();
};

#endif //FACTORY_OBSERVADOR_UBICABLE_H

