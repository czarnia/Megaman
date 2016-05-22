#include <stdio.h>
#include <string.h>

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

#include "servidor.h"
#include "test_mover.h"
#include <string>

#define POS_PUERTO 1

int main(int argc, char *argv[]){
  Servidor server(argv[POS_PUERTO]);
  server.aceptar_clientes();
  run_tests();

  /*while (!server.termino_partida()){
    server.actualizar_mundo();
    server.enviar_datos();
    clock
  }*/

  return 0;
}
