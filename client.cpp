#include "common_socket.h"

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char* id = argv[1];
  char* puerto = argv[2];
  Socket* cliente = new Socket(NULL, puerto);

  //Me conecto al servidor
  if ((*cliente).conect(id, puerto) < 0){
    std::cout << "Problema en conect \n";
    printf("%s \n", strerror(errno));
    return 0;
  }

  //Aca va el ciclo del cliente

  (*cliente).shutdown(SHUT_RDWR);
  delete cliente;
  return 0;
}
