#ifndef LOG_H
#define LOG_H

#include "../../../Comun/mutex.h"

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class Log{
  private:
    std::ofstream log_arch;
    std::map<int, std::string> jugadores;
    Mutex proteccion;
  public:
    //Se crea un Log.
    Log();
    //Destructor del Log.
    ~Log();
    void inicio_servidor();
    void fin_servidor();
    void cliente_conectado(std::string nombre_cliente);
    void cliente_desconectado(int id_cliente);
    void inicio_juego();
    void fin_juego();
    void inicio_nivel(int num_nivel);
    void fin_nivel();
    void jugador_atacar(int id_cliente, int direccion);
    void jugador_mover(int id_cliente, int direccion);
    void jugador_cambiar_arma(int id_cliente, int arma);
};

#endif //LOG_H
