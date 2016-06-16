#ifndef PREMIO_FACTORY_H
#define PREMIO_FACTORY_H

#include <iosfwd>
#include <cstddef>

#include "coordenada.h"
#include "premio.h"

class Premio_factory{
	public:
    //Dada una Coordenada, crea un premio.
    virtual Premio* crear(Coordenada c) = 0;
    //Devuelve la probabilidad de que un premio sea creado.
    virtual size_t probabilidad_de_crear() = 0;
};

#endif //PREMIO_FACTORY_H
