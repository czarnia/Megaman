#ifndef CREADOR_MOVER_H
#define CREADOR_MOVER_H

#include "creador_evento.h"
#include "evento.h"

class Creador_mover : public Creador_evento{
  private:
    int id;
  public:
    //Dado un id, crea un creador mover.
    Creador_mover(int id_creador);
    //Destructor del creador mover.
    virtual ~Creador_mover();
    //Crea un evento de tipo mover dado un parametro.
    virtual Evento* crear(int parametro);
};

#endif //CREADOR_MOVER_H
