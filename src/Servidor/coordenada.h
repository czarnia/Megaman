#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada{
  private:
    size_t x;
    size_t y;
  public:
    //Dada una ordenada y una abscisa, crea una Coordenada.
    Coordenada(size_t ordenada, size_t abscisa);
    //Devuelve la ordenada de la Coordenada.
    size_t obtener_ordenada();
    //Devuelve la abscisa de la Coordenada.
    size_t obtener_abscisa();
    //Calcula y devuelve la distancia entre la Coordenada y otra pasada por
    //parametro.
    size_t obtener_distancia(Coordenada otra_coordenada);
};

#endif //COORDENADA_H
