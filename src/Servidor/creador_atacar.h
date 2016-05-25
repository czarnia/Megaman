#ifndef CREADOR_ATACAR_H
#define CREADOR_ATACAR_H

#include "creador_evento.h"
#include "evento.h"

class Creador_atacar : class Creador_evento{
  private:
    int id;
  public:
    //Crea un evento de tipo atacar dado un parametro.
    virtual Evento* crear(int parametro);
};

#endif //CREADOR_ATACAR_H
