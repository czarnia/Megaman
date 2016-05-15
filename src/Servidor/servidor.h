#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <map>
#include <string>
#include "conexion_cliente.h"

class Servidor {
  private:
    //guardo a cada cliente con su id!
    std::map<std::string, Conexion_cliente*> clientes;
    Socket skt;
  public:
    //Crea un servidor.
    Servidor();
    //Destruye un servidor.
    ~Servidor();
    //Acepto a los clientes del servidor (maximo cuatro).
    void aceptar_clientes();
  private:
    //Dado un socket conectado a un cliente y un id del mismo, se agrega un cliente
    //al servidor.
    void agregar_cliente(Socket* cliente_nuevo, std::string id_cliente);
};

#endif //SERVIDOR_H
