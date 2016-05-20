#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada{
  private:
    size_t x;
    size_t y;
  public:
    //Dada una ordenada y una abscisa, crea una Coordenada.
    Coordenada(size_t ordenada, size_t abscisa);
    //Suma delta_x a la ordenada a la coordenada x;
    void sumar_abscisa(size_t delta_x);
	//Suma delta_y a la ordenada a la coordenada y;
	void sumar_ordenada(size_t delta_y);
    //Devuelve la ordenada de la Coordenada.
    size_t obtener_ordenada();
    //Devuelve la abscisa de la Coordenada.
    size_t obtener_abscisa();
    //Calcula y devuelve la distancia entre la Coordenada y otra pasada por
    //parametro.
    size_t obtener_distancia(Coordenada &otra_coordenada);
};

#endif //COORDENADA_H
