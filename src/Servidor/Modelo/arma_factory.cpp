#include "arma_factory.h"

ArmaFactory::ArmaFactory(Juego *juego): juego(juego){}

Arma_megaman* ArmaFactory::crear_arma_megaman(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_megaman *arma_megaman = new Arma_megaman(creados.size(), fact_obs);
	creados.insert(std::pair<Arma*, Factory_observador_ubicable *>(arma_megaman, fact_obs));
	return arma_megaman;
}

Arma_minion* ArmaFactory::crear_arma_minion(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_minion *arma_minion = new Arma_minion(creados.size(), fact_obs);
	creados.insert(std::pair<Arma*, Factory_observador_ubicable*>(arma_minion, fact_obs));
	return arma_minion;
}
