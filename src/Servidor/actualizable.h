#ifndef ACTUALIZABLE_H
#define ACTUALIZABLE_H

#include <cstddef>
#include "observador.h"

class Actualizable{
	private:
		std::vector<Observador*> observadores;
	public:
		//Hace que pase un tiempo para un actualizable.
		virtual void update(size_t tiempo) = 0;
		void agregar_observador(Observador *observador);
		void quitar_observador(Observador *observador);
		//Destructor del actualizable.
		virtual ~Actualizable() {}
};

#endif //ACTUALIZABLE_H
