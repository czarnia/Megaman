#ifndef CELDA_H
#define CELDA_H

#include "ubicable.h"

class Celda{
  private:
    bool ocupada;
    Ubicable &ocupante;
    Ubicable &obstaculo;
    int elemento;
  public:
    //Crea una celda con un elemento (aire, hielo, concreto o algun otro material de base)
    //es opcional, sirve para diseño del mapa: para saber si hay precipicio/vacio o tierra
    //si no recibe nada se asume que el elemento es vacío.
    //Recibe un único obstaculo (puas, escalon, etc.).
    Celda(Ubicable &obstaculo, int elemento);
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
    //Devuelve true si en la celda no hay ningún elemento
    //concreto, es decir si hay aire.
    bool esta_vacia();
};

#endif //CELDA_H
