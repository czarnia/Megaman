#include <stdio.h>
#include <string.h>

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include "unistd.h"

#include "servidor.h"
#include <string>

#define POS_PUERTO 1

int main(int argc, char *argv[]){
  Servidor server(argv[POS_PUERTO]);

  while (!server.termino_ejecucion()){
    server.aceptar_clientes();
    //server.empezar_partida();
  }
  return 0;
}
