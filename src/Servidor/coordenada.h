#ifndef COORDENADA_H
#define COORDENADA_H

#include <iosfwd>
#include <cstddef>

class Coordenada{
  private:
    size_t x;
    size_t y;
  public:
    //Dada una ordenada y una abscisa, crea una Coordenada.
    Coordenada(size_t ordenada, size_t abscisa);
    //Suma delta_x a la coordenada x;
    void sumar_abscisa(size_t delta_x);
	//Suma delta_y a la coordenada y;
	void sumar_ordenada(size_t delta_y);
    //Devuelve la ordenada de la Coordenada.
    size_t obtener_ordenada();
    //Devuelve la abscisa de la Coordenada.
    size_t obtener_abscisa();
    //Calcula y devuelve la distancia entre la Coordenada y otra pasada por
    //parametro.
    size_t obtener_distancia(Coordenada &otra_coordenada);
    //Devuelve la coordenada de arriba (tomando arriba como y-1).
    Coordenada arriba();
    //Devuelve la coordenada de abajo (tomando abajo como y+1).
    Coordenada abajo();
    //Devuelve la coordenada de la izquierda (tomando izquierda como x-1).
    Coordenada izquierda();
    //Devuelve la coordenada de la derecha (tomando derecha como x+1).
    Coordenada derecha();
    //Compara dos coordenadas.
    bool operator==(const Coordenada& otro) const;
    //Devuelve true si la coordenada tiene algun miembro negativo, false en caso
    //contrario.
    bool es_negativa();
};

#endif //COORDENADA_H
