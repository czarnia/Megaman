#ifndef CREADOR_ATACAR_H
#define CREADOR_ATACAR_H

#include "creador_evento.h"
#include "evento.h"

class Creador_atacar : public Creador_evento{
  private:
    int id;
  public:
    //Dado un id, crea un creador atacar.
    Creador_atacar(int id_creador);
    //Destructor del creador atacar.
    virtual ~Creador_atacar();
    //Crea un evento de tipo atacar dado un parametro.
    virtual Evento* crear(int parametro);
};

#endif //CREADOR_ATACAR_H
