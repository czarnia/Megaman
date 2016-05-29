#include "actualizable.h"

void Actualizable::agregar_observador(Observador *observador){
	observadores.push_back(observador);
}

void Actualizable::quitar_observador(Observador *observador){
	for (size_t i = 0; i < observadores.size(); i++){
		if (observadores[i] == observador){ 
			observadores.erase(observador);
		}
	}
}
