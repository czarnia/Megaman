#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observador.h"

class Observable{
	private:
		std::vector<Observador*> observadores;
	public:
		virtual void agregar_observador(Observador *observador);
		virtual void quitar_observador(Observador *observador);
		virtual void notificar_observadores() = 0;
		virtual ~Observable() = 0;
};

#endif //OBSERVABLE_H
