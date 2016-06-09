#ifndef CREADOR_START_H
#define CREADOR_START_H

#include "creador_evento_lobby.h"
#include "evento.h"

class Creador_start : public Creador_evento_lobby{
  private:
    int id;
  public:
    //Dado un id, crea un creador start.
    Creador_start(int id_creador);
    //Destructor del creador start.
    virtual ~Creador_start();
    //Crea un evento de tipo start dado un parametro.
    virtual Evento_lobby* crear(int parametro);
};

#endif //CREADOR_START_H
