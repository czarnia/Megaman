#include "observable.h"

void Observable::agregar_observador(Observador *observador){
	observadores.push_back(observador);
}

void Observable::quitar_observador(Observador *observador){
	for (size_t i = 0; i < observadores.size(); i++){
		if (observadores[i] == observador){
			observadores.erase(observadores.begin()+i);
		}
	}
}
