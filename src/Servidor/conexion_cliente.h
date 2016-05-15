#ifndef CONEXION_CLIENTE_H
#define CONEXION_CLIENTE_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"

class Conexion_cliente: public Hilo{
  private:
    Socket* skt;
    bool fin;
  public:
    //Crea una conexion_cliente recibiendo como parametro un socket ya conecta-
    //do.
    Conexion_cliente(Socket* conexion);
    //Ejecuta el "ciclo" de la conexion_cliente recibiendo informacion del clien
    //te.
    virtual void ejecutar();
    //Le informa a la conexion_cliente que debe dejar de recibir datos.
    void terminar_ejecucion();
};

#endif //CONEXION_CLIENTE_H
