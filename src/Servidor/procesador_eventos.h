#ifndef PROCESADOR_EVENTOS_H
#define PROCESADOR_EVENTOS_H

#include "evento.h"
#include "creador_evento.h"
#include <vector>
#include <string>

class Procesador_eventos{
  private:
    std::vector<Creador_evento*> creadores;
    int id;
  public:
    //Crea un procesador_eventos.
    Procesador_eventos(int id_procesador);
    //Dado un vector de ints que contiene el opcode de un evento, se crea al
    //mismo.
    Evento* crear_evento(int comando, int parametro);
  private:
    void generar_creadores();
};

#endif //PROCESADOR_EVENTOS_H
