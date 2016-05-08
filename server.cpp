#include <stdio.h>
#include <string.h>

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

#include "common_socket.h"
#include "server_procesador_servidor.h"
#include "server_accept.h"

int main(int argc, char *argv[]){
  char* puerto = argv[1];

  Procesador_servidor* server = new server();
  Accept aceptador(puerto, server);
  aceptador.start();

  std::getline(std::cin,linea_actual);
  while (linea_actual.compare("q") != 0){
    std::getline(std::cin,linea_actual);
  }

  aceptador.terminar();
  aceptador.join();

  delete conexion;
  return 0;
}
