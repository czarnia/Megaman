#include "arma_factory.h"

ArmaFactory::ArmaFactory(Juego *juego): juego(juego){
	creadas = 0;
}

Arma_megaman* ArmaFactory::crear_arma_megaman(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_megaman *arma_megaman = new Arma_megaman(creadas, fact_obs);
	creados.insert(std::pair<Arma*, Factory_observador_ubicable *>(arma_megaman, fact_obs));
	creadas++;
	return arma_megaman;
}

Arma_minion* ArmaFactory::crear_arma_minion(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_minion *arma_minion = new Arma_minion(creadas, fact_obs);
	creadas++;
	creados.insert(std::pair<Arma*, Factory_observador_ubicable*>(arma_minion, fact_obs));
	return arma_minion;
}

Arma_bombman* ArmaFactory::crear_arma_bombman(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_bombman *arma_bombman = new Arma_bombman(creadas, fact_obs);
	creadas++;
	creados.insert(std::pair<Arma*, Factory_observador_ubicable*>(arma_bombman, fact_obs));
	return arma_bombman;
}

Arma_sparkman* ArmaFactory::crear_arma_sparkman(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_sparkman *arma_sparkman = new Arma_sparkman(creadas, fact_obs);
	creadas++;
	creados.insert(std::pair<Arma*, Factory_observador_ubicable*>(arma_sparkman, fact_obs));
	return arma_sparkman;
}

Arma_ringman* ArmaFactory::crear_arma_ringman(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_ringman *arma_ringman = new Arma_ringman(creadas, fact_obs);
	creadas++;
	creados.insert(std::pair<Arma*, Factory_observador_ubicable*>(arma_ringman, fact_obs));
	return arma_ringman;
}

Arma_fireman* ArmaFactory::crear_arma_fireman(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_fireman *arma_fireman = new Arma_fireman(creadas, fact_obs);
	creadas++;
	creados.insert(std::pair<Arma*, Factory_observador_ubicable*>(arma_fireman, fact_obs));
	return arma_fireman;
}

Arma_magnetman* ArmaFactory::crear_arma_magnetman(){
	Factory_observador_ubicable *fact_obs = new Factory_observador_ubicable(juego);
	Arma_magnetman *arma_magnetman = new Arma_magnetman(creadas, fact_obs);
	creadas++;
	creados.insert(std::pair<Arma*, Factory_observador_ubicable*>(arma_magnetman, fact_obs));
	return arma_magnetman;
}

