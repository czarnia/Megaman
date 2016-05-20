#include "celda.h"

Celda(Plataforma p = NULL, Obstaculo* o = NULL){
	piso = p;
	obs = o;
}

bool ocupar(Personaje* ocupa){
	if (obs.puede_ocupar(ocupa)){
		ocupantes[ocupa.obtener_id()] = ocupa;
		return true;
	}
	return false;
}

bool puede_ocupar(Personaje* ocupa){
	if (!obs){
		return true;
	}
	return obs.puede_ocupar(ocupa);
}

Personaje* desocupar(std::string id_personaje){
	Personaje* ocupa = ocupantes[id_personaje]; //TODO: no devolver NULL, sino armar una excepcion
	if (ocupa){
		ocupantes.erase(id_personaje);
	}
	return ocupa;
}

Personaje* obtener_ocupante(std::string id_personaje){
	return ocupantes[id_personaje];
}
