#include "celda.h"

Celda::Celda(Ubicable &obstaculo, int elemento = -1){
	ocupada = false;
	elemento = elemento;
}

void Celda::ocupar(Ubicable ocupa){
	if (ocupada){
		return false;//se podria lanzar una excepcion tambien...
	}
	ocupante = ocupa;
	ocupada = true;
}

Ubicable Celda::desocupar(){
	if (!ocupada){
		return NULL; //TODO: agregar excepcion.
	}
	ocupada = false;
	return ubicable;
}

Ubicable Celda::obtener_ubicable(){
	if (!ocupada){
		return NULL;
	}
	return ubicable;
}

bool Celda::esta_vacia(){
	return (this->elemento != -1)
}

bool Celda::esta_ocupada(){
	return ocupada;
}
