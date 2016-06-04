#ifndef RECEIVER_CLIENTE_H
#define RECEIVER_CLIENTE_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"
#include "procesador_eventos.h"
#include "manejador_eventos.h"

class Juego;

class Receiver_cliente: public Hilo{
  private:
    Socket* skt;
    bool fin;
    int id_cliente;
    Procesador_eventos parser;
    Manejador_eventos handler;
  public:
    //Crea una Receiver_cliente recibiendo como parametro un socket ya conecta-
    //do y un id que lo identifica.
    Receiver_cliente(Socket* conexion, int id, Juego *m);
    //Ejecuta el "ciclo" de la Receiver_cliente recibiendo informacion del clien
    //te.
    virtual void ejecutar();
    //Le informa a la Receiver_cliente que debe dejar de recibir datos.
    void terminar_ejecucion();
    //Destructor del Receiver_cliente.
    virtual ~Receiver_cliente();
};

#endif //RECEIVER_CLIENTE_H
