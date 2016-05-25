#ifndef CREADOR_EVENTO_H
#define CREADOR_EVENTO_H

#include "evento.h"

class Creador_evento{
  public:
    //Crea un evento dado un parametro.
    virtual Evento* crear(int parametro) = 0;
};

#endif //CREADOR_EVENTO_H
