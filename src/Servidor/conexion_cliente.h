#ifndef CONEXION_CLIENTE_H
#define CONEXION_CLIENTE_H

#include "receiver_cliente.h"

class Conexion_cliente{
  private:
    Socket* skt;
    int id_cliente;
    Receiver_cliente rcv;
  public:
    //Crea una conexion_cliente recibiendo como parametro un socket ya conecta-
    //do y un id que lo identifica.
    Conexion_cliente(Socket* conexion, int id);
    //Le informa a la conexion_cliente que debe dejar de recibir datos.
    void terminar_ejecucion();
    //Destructor del Conexion_cliente.
    virtual ~Conexion_cliente();
};

#endif //CONEXION_CLIENTE_H
