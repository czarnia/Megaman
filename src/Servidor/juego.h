#ifndef JUEGO_H
#define JUEGO_H

#include "../Comun/mutex.h"
#include "actualizable.h"
#include "mapa.h"
#include "evento.h"
#include "strategy_mover.h"

#include <string>
#include <iosfwd>
#include <cstddef>


class Juego: public Actualizable{
  private:
    Mapa mundo;
    Mutex proteccion;
    bool fin_partida;
	public:
    //Crea un juego nuevo.
    Juego(size_t tamanio);
    //Destructor del juego.
		~Juego();
    //Implementa el ciclo del juego.
    void jugar();
    //Termina la partida en marcha.
    void terminar_partida();
    //Dado un determinado tiempo, actualiza al juego.
    virtual void update(size_t tiempo);
    //Dado el id de un personaje, hace que el mismo ataque en una direccion
    //dada.
    void personaje_atacar(std::string id_pj, StrategyMover* direccion);
    //Dado el id de un personaje, hace que el mismo se mueva en una direccion
    //dada.
    void personaje_mover(std::string id_pj, StrategyMover* direccion);
    //Dado el id de un personaje y un numero de arma, hace que el mismo cambie a
    //la misma.
    void personaje_cambiar_arma(std::string id_pj, int arma);
};

#endif //JUEGO_H
