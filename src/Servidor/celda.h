#ifndef CELDA_H
#define CELDA_H

#include <iosfwd>
#include <cstddef>
#include "coordenada.h"

class Celda{
  protected:
    Coordenada coordenadas;
  public:
    //Devuelve true si se puede ubicar un personaje o elemento en la celda, fal-
    //se en caso contrario.
    virtual bool puedo_ubicar() = 0;
    //Destructor de la celda.
    virtual ~Celda();

    //Devuelve la coordenada de la celda de la derecha a si misma.
    virtual Coordenada celda_derecha(){
      return coordenadas.derecha();
    }
    //Devuelve la coordenada de la celda de la izquierda a si misma.
    virtual Coordenada celda_izquierda(){
      return coordenadas.izquierda();
    }
    //Devuelve la coordenada de la celda de arriba a si misma.
    virtual Coordenada celda_arriba(){
      return coordenadas.arriba();
    }
    //Devuelve la coordenada de la celda de abajo a si misma.
    virtual Coordenada celda_abajo(){
      return coordenadas.abajo();
    }
    //Devuelve la coordenada de la celda en diagonal abajo a la derecha a si
    //misma.
    virtual Coordenada celda_diagonal_derabajo(){
      return coordenadas.derecha().abajo();
    }
    //Devuelve la coordenada de la celda en diagonal arriba a la derecha a si
    //misma.
    virtual Coordenada celda_diagonal_derarriba(){
      return coordenadas.derecha().arriba();
    }
    //Devuelve la coordenada de la celda en diagonal abajo a la izquierda a si
    //misma.
    virtual Coordenada celda_diagonal_izqabajo(){
      return coordenadas.izquierda().abajo();
    }
    //Devuelve la coordenada de la celda en diagonal arriba a la izquierda a si
    //misma.
    virtual Coordenada celda_diagonal_izqarriba(){
      return coordenadas.izquierda().arriba();
    }
};
#endif //CELDA_H
