#ifndef PROCESADOR_SERVIDOR_H
#define PROCESADOR_SERVIDOR_H

#include "server_almacenamiento_reducers.h"

#include <vector>
#include <map>
#include <string>

class Conexion_cliente;

class Procesador_servidor{
  private:
    std::vector<Conexion_cliente*> clientes;
  public:
    //Crea un procesador_servidor.
    Procesador_servidor();
    //Destruye un procesador_servidor.
    ~Procesador_servidor();
    //Dada una conexion_cliente*, lo agrega al servidor.
    void agregar_cliente(Conexion_cliente* cliente);
    //Ejecuta a los reducers.
    void join();
};

#endif // PROCESADOR_SERVIDOR_H
