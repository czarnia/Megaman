#include "server_conexion_cliente.h"
#include "common_socket.h"


Conexion_cliente::Conexion_cliente(Socket* conexion, Procesador_servidor* srv)
:skt(conexion){
  server = srv;
}

Conexion_cliente::~Conexion_cliente(){
  delete skt;
}

void Conexion_cliente::ejecutar(){
}
