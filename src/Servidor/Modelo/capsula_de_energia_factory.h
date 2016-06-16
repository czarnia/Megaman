#ifndef CAPSULA_DE_ENERGIA_FACTORY_H
#define CAPSULA_DE_ENERGIA_FACTORY_H

#include "premio_factory.h"

class Capsula_de_energia_factory : public Premio_factory{
	public:
    //Dada una Coordenada, crea una capsula de energia.
    virtual Premio* crear(Coordenada c);
    //Devuelve la probabilidad de que una capsula de energia sea creada.
    virtual size_t probabilidad_de_crear();
};

#endif //CAPSULA_DE_ENERGIA_FACTORY_H
