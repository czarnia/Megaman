#ifndef CONEXION_CLIENTE_H
#define CONEXION_CLIENTE_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"

class Conexion_cliente: public Hilo{
  private:
    Socket* skt;
  public:
    Conexion_cliente(Socket* conexion);
    virtual void ejecutar();
};

#endif //CONEXION_CLIENTE_H
