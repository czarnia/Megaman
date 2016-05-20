#ifndef CELDA_H
#define CELDA_H

#include "ubicable.h"
#include <vector>

class Celda{
  private:
    bool ocupada;
    std::vector <Ubicable*> ocupantes;
    int elemento;
  public:
    //Crea una celda. Opcionalmente se le puede asignar un obstaculo.
    //Los obstaculos ocupan la celda y no permiten que un personaje
    //las atraviese.
    Celda(Ubicable &obstaculo);
    //Dado un ubicable, lo ubica en la celda.
    //Devuelve true sólo si se pudo agregar el 
    //ocupante a la celda.
    bool ocupar(Ubicable &ocupa);
    //Devuelve true sólo si es posible agregar el 
    //ocupante a la celda.    
    bool puede_ocupar(Ubicable &ocupa);
    //Saca al ubicable que estaba en una celda y lo devuelve.
    //TODO: agregar una excepcion en caso de que no haya ubicable.
    Ubicable *desocupar();
    //Devuelve al ubicable que ocupa la celda.
    //TODO: agregar una excepcion en caso de que no haya ubicable.
    Ubicable *obtener_ubicable();
    //Devuelve true si la celda esta ocupada, false en caso contrario.
    bool esta_ocupada();
};

#endif //CELDA_H
