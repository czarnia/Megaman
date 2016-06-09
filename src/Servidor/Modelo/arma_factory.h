#ifndef ARMA_FACTORY_H
#define ARMA_FACTORY_H

#include "arma.h"
#include "arma_megaman.h"
#include "arma_met.h"
#include "factory_observador_ubicable.h"
#include <map>

class ArmaFactory {
	private:
		std::map<Arma*, Factory_observador_ubicable *> creados;
		Juego *juego;
	public:
		ArmaFactory(Juego *j);
		Arma_megaman* crear_arma_megaman();
		Arma_met* crear_arma_met();
};

#endif //ARMA_FACTORY_H
