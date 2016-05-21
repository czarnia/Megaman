#ifndef CELDA_H
#define CELDA_H

#include "coordenada.h"

class Celda{
  public:
    virtual bool puedo_ubicar() = 0;
    virtual Coordenada celda_derecha() = 0;
    virtual Coordenada celda_izquierda() = 0;
    virtual Coordenada celda_arriba() = 0;
    virtual Coordenada celda_abajo() = 0;
    virtual Coordenada celda_diagonal_derabajo() = 0;
    virtual Coordenada celda_diagonal_derarriba() = 0;
    virtual Coordenada celda_diagonal_izqabajo() = 0;
    virtual Coordenada celda_diagonal_izqarriba() = 0;
    virtual ~Celda();
};

#endif //CELDA_H
