#ifndef RECEIVER_H
#define RECEIVER_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"

class Receiver: public Hilo{
  private:
    Socket* skt;
  public:
    //Crea un receiver recibiendo como parametro un socket ya conectado.
    Receiver(Socket* conexion);
    //"Ciclo" del receiver, recibe informacion del servidor hasta que el mismo
    //le indica el fin de la ejecucion.
    virtual void ejecutar();
};

#endif //RECEIVER_H
