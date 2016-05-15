#include <stdio.h>
#include <string.h>

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

#include "servidor.h"
#include <string>

#define MAX_CONEXIONES 4

int main(int argc, char *argv[]){
  Servidor server();
  server.aceptar_clientes();

  /*while (!server.termino_partida()){
    server.actualizar_mundo();
    server.enviar_datos();
    clock
  }*/

  return 0;
}
