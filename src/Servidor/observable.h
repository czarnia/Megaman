#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observador.h"
#include <vector>

class Observable{
	protected:
		std::vector<Observador*> observadores;
	public:
		//Dado un observador, lo agrega.
		virtual void agregar_observador(Observador *observador);
		//Dado un observador, lo quita.
		virtual void quitar_observador(Observador *observador);
		//Notifica a los observadores.
		virtual void notificar_observadores() = 0;
		//Destructor del observable.
		virtual ~Observable() = 0;
};

#endif //OBSERVABLE_H
