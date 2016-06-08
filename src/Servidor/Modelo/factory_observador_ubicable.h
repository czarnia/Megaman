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
		//Dado un juego*, crea un Factory_observador_ubicable.
		Factory_observador_ubicable(Juego *j);
		//Dado un ubicable, crea un observador_ubicable y se lo agrega.
		void crear(Ubicable *obs);
		//Destructor del Factory_observador_ubicable
		~Factory_observador_ubicable();
};

#endif //FACTORY_OBSERVADOR_UBICABLE_H
