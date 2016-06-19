#ifndef ARMA_FACTORY_H
#define ARMA_FACTORY_H

#include "arma.h"
#include "arma_megaman.h"
#include "arma_minion.h"
#include "arma_bombman.h"
#include "arma_ringman.h"
#include "arma_fireman.h"
#include "arma_sparkman.h"
#include "arma_magnetman.h"
#include "factory_observador_ubicable.h"
#include <map>

class ArmaFactory {
	private:
		int creadas;
		std::map<Arma*, Factory_observador_ubicable *> creados;
		Juego *juego;
	public:
		//Dado un Juego*, crea un ArmaFactory.
		ArmaFactory(Juego *j);
		//Crea un Arma_megaman*.
		Arma_megaman* crear_arma_megaman();
		//Crea un Arma_minion*.
		Arma_minion* crear_arma_minion();
		//Crea un Arma_bombman*.
		Arma_bombman* crear_arma_bombman();
		//Crea un Arma_sparkman*.
		Arma_sparkman* crear_arma_sparkman();
		//Crea un Arma_fireman*.
		Arma_fireman* crear_arma_fireman();
		//Crea un Arma_magnetman*.
		Arma_magnetman* crear_arma_magnetman();
		//Crea un Arma_ringman*.
		Arma_ringman* crear_arma_ringman();
};

#endif //ARMA_FACTORY_H
