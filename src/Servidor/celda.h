#ifndef CELDA_H
#define CELDA_H

#include <iosfwd>
#include <cstddef>
#include "coordenada.h"

class Celda{
  protected:
    Coordenada *coordenadas;
  public:
	Celda(size_t x, size_t y);
    //Devuelve true si se puede ubicar un personaje o elemento en la celda, fal-
    //se en caso contrario.
    virtual bool puedo_ubicar() = 0;
    //Devuelve la coordenada de la celda de la derecha a si misma.
    virtual Coordenada celda_derecha();
    //Devuelve la coordenada de la celda de la izquierda a si misma.
    virtual Coordenada celda_izquierda();
    //Devuelve la coordenada de la celda de arriba a si misma.
    virtual Coordenada celda_arriba();
    //Devuelve la coordenada de la celda de abajo a si misma.
    virtual Coordenada celda_abajo();
    //Devuelve la coordenada de la celda en diagonal abajo a la derecha a si
    //misma.
    virtual Coordenada celda_diagonal_derabajo();
    //Devuelve la coordenada de la celda en diagonal arriba a la derecha a si
    //misma.
    virtual Coordenada celda_diagonal_derarriba();
    //Devuelve la coordenada de la celda en diagonal abajo a la izquierda a si
    //misma.
    virtual Coordenada celda_diagonal_izqabajo();
    //Devuelve la coordenada de la celda en diagonal arriba a la izquierda a si
    //misma.
    virtual Coordenada celda_diagonal_izqarriba();
    //Destructor de la celda.
    virtual ~Celda() = 0;
};
#endif //CELDA_H
