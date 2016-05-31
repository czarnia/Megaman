#ifndef ESCALERA_H
#define ESCALERA_H

#include "personaje.h"
#include "elemento.h"
#include "coordenada.h"
#include "mapa.h"

class Escalera: public Elemento{
	public:
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Personaje* pj);
		//Recibe un personaje e interactúa con el mismo
		//para actualizar sus coordenadas:
		void interactuar(Personaje *pj);
		//Destructor de la Escalera.
		~Escalera();
};

#endif //ESCALERA_H
