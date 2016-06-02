#ifndef CREADOR_PARAR_H
#define CREADOR_PARAR_H

#include "creador_evento.h"
#include "evento.h"

class Creador_parar : public Creador_evento{
  private:
    int id;
  public:
    //Dado un id, crea un creador parar.
    Creador_parar(int id_creador);
    //Destructor del creador parar.
    virtual ~Creador_parar();
    //Crea un evento de tipo parar dado un parametro.
    virtual Evento* crear(int parametro);
};

#endif //CREADOR_PARAR_H
