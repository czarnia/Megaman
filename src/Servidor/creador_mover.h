#ifndef CREADOR_MOVER_H
#define CREADOR_MOVER_H

#include "creador_evento.h"
#include "evento.h"

class Creador_mover : class Creador_evento{
  private:
    int id;
  public:
    //Crea un evento de tipo mover dado un parametro.
    virtual Evento* crear(int parametro);
};

#endif //CREADOR_MOVER_H
