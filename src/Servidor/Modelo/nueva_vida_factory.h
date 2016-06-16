#ifndef NUEVA_VIDA_FACTORY_H
#define NUEVA_VIDA_FACTORY_H

#include "premio_factory.h"

class Nueva_vida_factory : public Premio_factory{
	public:
    //Dada una Coordenada, crea una nueva vida.
    virtual Premio* crear(Coordenada c);
    //Devuelve la probabilidad de que una nueva_vida sea creada.
    virtual size_t probabilidad_de_crear();
};

#endif //NUEVA_VIDA_FACTORY_H
