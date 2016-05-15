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
    Servidor();
    ~Servidor();
    void aceptar_clientes();
  private:
    void agregar_cliente(Socket* cliente_nuevo, std::string id_cliente);
};

#endif //SERVIDOR_H
