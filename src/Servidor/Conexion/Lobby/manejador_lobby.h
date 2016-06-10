#ifndef MANEJADOR_LOBBY_H
#define MANEJADOR_LOBBY_H

#include "../Arquitectura/log.h"

class Evento_lobby;
class Servidor;

class Manejador_lobby{
  private:
    Servidor* srv;
    Log* l;
  public:
    //Dado un servidor, crea un manejador de lobby.
    Manejador_lobby(Servidor *s, Log* lg);
    //Destructor del manejador de lobby.
    ~Manejador_lobby();
    //Dado un evento_lobby, lo ejecuta.
    void ejecutar_evento(Evento_lobby* e);
};

#endif //MANEJADOR_LOBBY_H
