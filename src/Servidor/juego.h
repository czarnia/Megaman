#ifndef JUEGO_H
#define JUEGO_H

#include "actualizable.h"
#include "mapa.h"
#include "../Comun/mutex.h"

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
    //El juego recibe un evento y lo procesa.
    void procesar_evento(Evento* e);
};

#endif //JUEGO_H
