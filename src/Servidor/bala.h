#ifndef BALA_H
#define BALA_H

#include "actualizable.h"
#include "personaje.h"
#include "mapa.h"

class Bala: public Actualizable, public Elemento{
	public:
    //Destructor de la bala.
		virtual ~Bala();
    //Dado un personaje y un mapa, interactua con el personaje.
    virtual void interactuar(Mapa &mapa, Personaje *pj) = 0;
    //Dado un personaje, dice si puede ubicarse en las mismas coordenadas que
    //este.
		virtual bool puede_ocupar(Personaje *pj);
    //Hace que pasa el tiempo para la bala.
    virtual void update(size_t tiempo);
};

#endif //BALA_H
