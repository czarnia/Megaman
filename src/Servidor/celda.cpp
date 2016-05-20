#include "celda.h"

Celda::Celda(){
	this->ocupada = false;
}

Celda::Celda(Ubicable &ocupa){
	this->ocupantes.push_back(&(*ocupa));
	this->ocupada = !ocupa.puede_compartir_celda();
}

bool Celda::puede_ocupar(Ubicable &ocupa){
	for (size_t i = 0; i < ocupantes.size(); i++){
		if (!ocupantes[i].es_ubicable_con(ocupa)){
			return false;
		}
	}
	return true;
}

bool Celda::ocupar(Ubicable &ocupa){
	if (ocupada || (!puede_ocupar(ocupa))){
		return false;
	}
	this->ocupantes.push_back(&(*ocupa));
	ocupada = (ocupada || !ocupa.puede_compartir_celda());
	return true;
}

Ubicable *Celda::desocupar(){
	if (!ocupada){
		return NULL; //TODO: agregar excepcion.
	}
	for (size_t i = 0; i < ocupantes.size(); i++){
		if (!ocupantes[i].puede_compartir_celda()){
			Ubicable *ocupa = ocupantes[i];
			ocupantes.erase(ocupantes.begin() + i);
			ocupada = false;
			return ocupa;
		}
	}
}

Ubicable *Celda::obtener_ubicable(){
	if (!ocupada){
		return NULL;
	}
	for (size_t i = 0; i < ocupantes.size(); i++){
		if (!ocupantes[i].puede_compartir_celda()){
			Ubicable *ocupa = ocupantes[i];
			return ocupa;
		}
	}
}

bool Celda::esta_ocupada(){
	return ocupada;
}
