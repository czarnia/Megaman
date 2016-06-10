#ifndef PROCESADOR_LOBBY_H
#define PROCESADOR_LOBBY_H

#include "evento_lobby.h"
#include "creador_evento_lobby.h"

#include <vector>

class Procesador_lobby{
  private:
    std::vector<Creador_evento_lobby*> creadores;
    int id;
  public:
    //Crea un procesador_lobby.
    Procesador_lobby(int id_procesador);
    //Dado un vector de ints que contiene el opcode de un evento, se crea al
    //mismo.
    Evento_lobby* crear_evento(int comando, int parametro);
  private:
    //Crea los generadores de los lobby.
    void generar_creadores();
};

#endif //PROCESADOR_LOBBY_H
