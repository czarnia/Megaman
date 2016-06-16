#ifndef CAPSULA_DE_PLASMA_FACTORY_H
#define CAPSULA_DE_PLASMA_FACTORY_H

#include "premio_factory.h"

class Capsula_de_plasma_factory : public Premio_factory{
	public:
    //Dada una Coordenada, crea una capsula de plasma.
    virtual Premio* crear(Coordenada c);
    //Devuelve la probabilidad de que una capsula de plasma sea creada.
    virtual size_t probabilidad_de_crear();
};

#endif //CAPSULA_DE_PLASMA_FACTORY_H
