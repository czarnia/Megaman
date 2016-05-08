#ifndef CONEXION_SERVIDOR_H
#define CONEXION_SERVIDOR_H

#include "server_hilo.h"
#include "common_socket.h"
#include "server_procesador_servidor.h"

class Conexion_servidor : public Hilo{
  private:
    Socket* skt;
  public:
    //Dado un socket crea una conexion_servidor.
    Conexion_servidor(Socket* conexion);
    //Destruye una conexion_servidor.
    ~Conexion_servidor();
    //Recibe datos de un socket hasta encontrarse con una señal de fin.
    void ejecutar();
};

#endif //CONEXION_SERVIDOR_H
