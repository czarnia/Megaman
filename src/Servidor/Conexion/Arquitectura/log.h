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
    const char* path;
    std::map<int, std::string> jugadores;
    Mutex proteccion;

    static Log* singleton;
    static bool hay_instancia;
  public:
    //Devuelve una instancia de Log.
    static Log* instancia();
    //Destructor del Log.
    ~Log();
    //Escribe en el archivo de salida un mensaje referido a que se inicia el
    //servidor.
    void inicio_servidor();
    //Escribe en el archivo de salida un mensaje referido a que se cierra el
    //servidor.
    void fin_servidor();
    //Escribe en el archivo de salida un mensaje referido a que se conecta un
    //cliente.
    void cliente_conectado(std::string nombre_cliente);
    //Escribe en el archivo de salida un mensaje referido a que se desconecta un
    //cliente.
    void cliente_desconectado(int id_cliente);
    //Escribe en el archivo de salida un mensaje referido a que se inicia el
    //juego.
    void inicio_juego();
    //Escribe en el archivo de salida un mensaje referido a que se finaliza el
    //juego.
    void fin_juego();
    //Escribe en el archivo de salida un mensaje referido a que se inicia un
    //nivel.
    void inicio_nivel(int num_nivel);
    //Escribe en el archivo de salida un mensaje referido a que se finaliza un
    //nivel.
    void fin_nivel();
    //Escribe en el archivo de salida un mensaje referido a que un jugador ata-
    //ca.
    void jugador_atacar(int id_cliente, int direccion);
    //Escribe en el archivo de salida un mensaje referido a que un jugador se
    //mueve.
    void jugador_mover(int id_cliente, int direccion);
    //Escribe en el archivo de salida un mensaje referido a que un jugador cam-
    //bia su arma.
    void jugador_cambiar_arma(int id_cliente, int arma);
  private:
    //Se crea un Log.
    Log();

};

#endif //LOG_H
