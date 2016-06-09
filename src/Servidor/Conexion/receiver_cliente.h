#ifndef RECEIVER_CLIENTE_H
#define RECEIVER_CLIENTE_H

#include "../../Comun/hilo.h"
#include "../../Comun/socket.h"
#include "procesador_eventos.h"
#include "manejador_eventos.h"
#include "procesador_lobby.h"
#include "manejador_lobby.h"

class Juego;
class Servidor;

class Receiver_cliente: public Hilo{
  private:
    Socket* skt;
    bool fin;
    bool jugando;
    int id_cliente;
    Procesador_eventos parser_juego;
    Manejador_eventos handler_juego;
    Procesador_lobby parser_lobby;
    Manejador_lobby handler_lobby;
  public:
    //Crea una Receiver_cliente recibiendo como parametro un socket ya conecta-
    //do y un id que lo identifica.
    Receiver_cliente(Socket* conexion, int id, Juego *m, Servidor* s);
    //Ejecuta el "ciclo" de la Receiver_cliente recibiendo informacion del clien
    //te.
    virtual void ejecutar();
    //Le informa a la Receiver_cliente que debe dejar de recibir datos.
    void terminar_ejecucion();
    //Le informa a la Receiver_cliente que se ha iniciado un nivel.
    void iniciar_nivel();
    //Le informa a la Receiver_cliente que se ha terminado un nivel.
    void finalizar_nivel();
    //Destructor del Receiver_cliente.
    virtual ~Receiver_cliente();
};

#endif //RECEIVER_CLIENTE_H
