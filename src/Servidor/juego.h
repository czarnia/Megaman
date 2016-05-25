#ifndef JUEGO_H
#define JUEGO_H

#include "../Comun/mutex.h"
#include "actualizable.h"
#include "mapa.h"
#include "evento.h"


#include <iosfwd>
#include <cstddef>


class Juego: public Actualizable{
  private:
    Mapa mundo;
    Mutex proteccion;
	public:
    //Crea un juego nuevo.
    Juego(size_t tamanio);
    //Destructor del juego.
		~Juego();
    //Dado un determinado tiempo, actualiza al juego.
    virtual void update(size_t tiempo);
};

#endif //JUEGO_H
