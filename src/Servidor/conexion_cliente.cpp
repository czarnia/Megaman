#include "conexion_cliente.h"

Conexion_cliente::Conexion_cliente(Socket* conexion, int id) : skt(conexion), id_cliente(id),
rcv(conexion, id) {
  rcv.start();
}

void Conexion_cliente::terminar_ejecucion(){
  rcv.terminar_ejecucion();
}

Conexion_cliente::~Conexion_cliente(){
  rcv.join();
}
