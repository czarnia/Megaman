#ifndef CELDA_H
#define CELDA_H

#include "ubicable.h"

class Celda{
  private:
    bool ocupada;
    Ubicable ocupante;
  public:
    //Crea una celda.
    Celda();
    //Dado un ubicable, lo ubica en la celda.
    void ocupar(Ubicable ocupa);
    //Saca al ubicable que estaba en una celda y lo devuelve.
    //TODO: agregar una excepcion en caso de que no haya ubicable.
    Ubicable desocupar();
    //Devuelve al ubicable que ocupa la celda.
    //TODO: agregar una excepcion en caso de que no haya ubicable.
    Ubicable obtener_ubicable();
    //Devuelve true si la celda esta ocupada, false en caso contrario.
    bool esta_ocupada();
};

#endif //CELDA_H
