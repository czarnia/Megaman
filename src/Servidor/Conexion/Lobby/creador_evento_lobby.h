#ifndef CREADOR_EVENTO_LOBBY_H
#define CREADOR_EVENTO_LOBBY_H

#include "evento_lobby.h"

class Creador_evento_lobby{
  public:
    //Crea un evento_lobby dado un parametro.
    virtual Evento_lobby* crear(int parametro) = 0;
};

#endif //CREADOR_EVENTO_LOBBY_H
