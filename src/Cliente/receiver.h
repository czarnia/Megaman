#ifndef RECEIVER_H
#define RECEIVER_H

#include "hilo.h"
#include "socket.h"

class Receiver: public Hilo{
  private:
    Socket* skt;
  public:
    Receiver(Socket* conexion);
    virtual void ejecutar();
};

#endif //RECEIVER_H
