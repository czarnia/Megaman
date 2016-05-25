#ifndef CONEXION_CLIENTE_H
#define CONEXION_CLIENTE_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"
#include "procesador_eventos.h"
#include "manejador_eventos.h"

class Conexion_cliente: public Hilo{
  private:
    Socket* skt;
    bool fin;
    int id_cliente;
    Procesador_eventos parser;
    Manejador_eventos handler;
  public:
    //Crea una conexion_cliente recibiendo como parametro un socket ya conecta-
    //do y un id que lo identifica.
    Conexion_cliente(Socket* conexion, int id);
    //Ejecuta el "ciclo" de la conexion_cliente recibiendo informacion del clien
    //te.
    virtual void ejecutar();
    //Le informa a la conexion_cliente que debe dejar de recibir datos.
    void terminar_ejecucion();
    //Destructor del Conexion_cliente.
    virtual ~Conexion_cliente();
};

#endif //CONEXION_CLIENTE_H
